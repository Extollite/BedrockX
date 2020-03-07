#include "pch.h"
#include <cassert>
KVDBImpl::KVDBImpl(const char* path, bool read_cache, int cache_sz) {
	rdopt = leveldb::ReadOptions();
	wropt = leveldb::WriteOptions();
	rdopt.fill_cache = read_cache;
	rdopt.verify_checksums = false;
	wropt.sync = false;
	if (cache_sz) {
		options.block_cache = leveldb::NewLRUCache(cache_sz);
	}
	options.reuse_logs = true; //WARN:EXPERIMENTAL
	options.create_if_missing = true;
	leveldb::Status status = leveldb::DB::Open(options, path, &db);
	if (!status.ok()) {
		printf("cannot load %s reason: %s", path, status.ToString().c_str());
	}
	assert(status.ok());
}
KVDBImpl::~KVDBImpl() {
	delete db;
}
bool KVDBImpl::get(string_view key, string& val) {
	return db->Get(rdopt, leveldb::Slice(key.data(), key.size()), &val).ok();
}
void KVDBImpl::put(string_view key, string_view val) {
	db->Put(wropt, leveldb::Slice(key.data(), key.size()), leveldb::Slice(val.data(), val.size()));
}
void KVDBImpl::del(string_view key) {
	db->Delete(wropt, leveldb::Slice(key.data(), key.size()));
}
void KVDBImpl::iter(std::function<bool(string_view key)>&& fn) {
	leveldb::Iterator* it = db->NewIterator(rdopt);
	for (it->SeekToFirst(); it->Valid(); it->Next()) {
		auto k = it->key();
		fn({ k.data(), k.size() });
	}
	delete it;
}
void KVDBImpl::iter(std::function<bool(string_view key, string_view val)>&& fn) {
	leveldb::Iterator* it = db->NewIterator(rdopt);
	for (it->SeekToFirst(); it->Valid(); it->Next()) {
		auto k = it->key();
		auto v = it->value();
		fn({ k.data(), k.size() }, { v.data(), v.size() });
	}
	delete it;
}
