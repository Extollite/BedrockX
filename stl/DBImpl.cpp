#include <lbpch.h>
#include <stl\KVDB.h>
LIGHTBASE_API std::unique_ptr<KVDBImpl> MakeKVDB(const string& path, bool read_cache, int cache_sz, int Bfilter_bit) {
	auto db = make_unique<KVDBImpl>();
	db->__init(path.c_str(),read_cache,cache_sz,Bfilter_bit);
	return db;
}
void KVDBImpl::__init(const char* path, bool read_cache, int cache_sz, int Bfilter_bit) {
	rdopt = leveldb::ReadOptions();
	wropt = leveldb::WriteOptions();
	options = leveldb::Options();
	rdopt.fill_cache = read_cache;
	rdopt.verify_checksums = false;
	wropt.sync = false;
	if (cache_sz) {
		options.block_cache = leveldb::NewLRUCache(cache_sz);
	}
	options.reuse_logs = true; //WARN:EXPERIMENTAL
	options.create_if_missing = true;
	dpath = path;
	if (Bfilter_bit)
		options.filter_policy = leveldb::NewBloomFilterPolicy(Bfilter_bit);
	leveldb::Status status = leveldb::DB::Open(options, path, &db);
	if (!status.ok()) {
		printf("cannot load %s reason: %s", path, status.ToString().c_str());
	}
	assert(status.ok());
}
KVDBImpl::~KVDBImpl() {
	if (options.filter_policy)
		delete options.filter_policy;
	delete db;
}
bool KVDBImpl::get(string_view key, string& val) {
	auto s = db->Get(rdopt, leveldb::Slice(key.data(), key.size()), &val);
	if (!s.ok()) {
		if (s.IsNotFound())
			return false;
		printf("[DB Error]get %s %s\n",dpath.c_str(),s.ToString().c_str());
	}
	return true;
}
void KVDBImpl::put(string_view key, string_view val) {
	auto s=db->Put(wropt, leveldb::Slice(key.data(), key.size()), leveldb::Slice(val.data(), val.size()));
	if (!s.ok()) {
		printf("[DB Error]put %s %s\n", dpath.c_str(), s.ToString().c_str());
	}
}
void KVDBImpl::del(string_view key) {
	auto s=db->Delete(wropt, leveldb::Slice(key.data(), key.size()));
	if (!s.ok()) {
		printf("[DB Error]del %s %s\n", dpath.c_str(), s.ToString().c_str());
	}
}
void KVDBImpl::iter(std::function<bool(string_view key)> const& fn) {
	leveldb::Iterator* it = db->NewIterator(rdopt);
	for (it->SeekToFirst(); it->Valid(); it->Next()) {
		auto k = it->key();
		if (!fn({ k.data(), k.size() }))
			break;
	}
	delete it;
}
void KVDBImpl::iter(std::function<bool(string_view key, string_view val)> const& fn) {
	leveldb::Iterator* it = db->NewIterator(rdopt);
	for (it->SeekToFirst(); it->Valid(); it->Next()) {
		auto k = it->key();
		auto v = it->value();
		if (!fn({ k.data(), k.size() }, { v.data(), v.size() }))
			break;
	}
	delete it;
}