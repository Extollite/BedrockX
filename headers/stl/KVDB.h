#pragma once
#include<functional>
#include<string_view>
#include<unordered_map>
using std::string_view,std::string;
class MallocVal;
class KVDBImpl {
    std::unordered_map<string, string> vdb;
public:
    KVDBImpl(const char* path);
    MallocVal get(string_view key);
    void put(string_view key, string_view val);
    void del(string_view key);
    void iter(std::function<bool(string_view key)>f);
    void iter(std::function<bool(string_view key, string_view val)>);
    static void free(void* ptr);
};
class MallocVal {
public:
    void* data;
    size_t len;
    MallocVal(void* d, size_t le) {
        data = d;
        len = le;
    }
    ~MallocVal() {
        if (data) KVDBImpl::free(data);
    }
    bool empty() {
        return data == NULL;
    }
    constexpr operator string_view() {
        return string_view((const char*)data, len);
    }
    operator bool() {
        return data;
    }
};
