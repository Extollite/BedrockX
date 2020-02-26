#include "pch.h"
#include <cassert>
KVDBImpl::KVDBImpl(const char* path) {
}
MallocVal KVDBImpl::get(string_view key) {
	auto it = vdb.find(string(key));
	if (it == vdb.end()) {
		return MallocVal(NULL, 0);
	}
	else {
		void* mem = malloc(it->second.size());
		if (mem) {
			memcpy(mem, it->second.data(), it->second.size());
			return MallocVal(mem, it->second.size());
		}
	}
	assert(false);
	return MallocVal(NULL, 0);
}
void KVDBImpl::put(string_view key, string_view val) {
	vdb[string(key)] = string(val);
}
void KVDBImpl::del(string_view key) {
	vdb.erase(string(key));
}
void KVDBImpl::iter(std::function<bool(string_view key)>&& f) {
}
void KVDBImpl::iter(std::function<bool(string_view key, string_view val)>&& f) {
}
void KVDBImpl::free(void* ptr) {
	::free(ptr);
}