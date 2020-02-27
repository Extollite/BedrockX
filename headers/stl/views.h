#pragma once
#include <cstdint>
#include <string_view>
using std::string_view;
template<typename T>
inline string_view to_view(T& x) {
    return string_view((const char*)&x, sizeof(T));
}

class split_view
{
private:
    const char* now;
    const char* next;
    const char* cend;
    string_view delim;
    const char* __find(const char* start)
    {
        const char* _now = start;
        while (_now < cend)
        {
            if (_now + delim.size() > cend) {
                return cend;
            }
            if (memcmp(_now, delim.data(), delim.size()) == 0)
                return _now;
            ++_now;
        }
        return _now;
    }

public:
    split_view(string_view sv, string_view split = ",")
    {
        delim = split;
        now = sv.data();
        cend = sv.data() + sv.size();
        next = __find(now);
    }
    bool end()
    {
        return now >= cend;
    }
    operator bool() {
        return !end();
    }
    void operator++()
    {
        now = next + delim.size();
        next = __find(now);
    }
    string_view get()
    {
        return string_view(now, next - now);
    }
    string_view operator*() {
        return get();
    }
};
template <typename T>
class array_view
{
private:
    T* view_start;
    T* view_end;

public:
    array_view(string_view sv)
    {
        view_start = (T*)sv.data();
        view_end = (T*)(sv.data() + sv.size());
        //dbg_assert(((uintptr_t)view_end - (uintptr_t)view_start) % sizeof(T) == 0);
    }
    array_view(T* start, T* end) {
		view_start = start;
		view_end = end;
    }
    size_t size()
    {
        return ((uintptr_t)view_end - (uintptr_t)view_start) / sizeof(T);
    }
    T& operator[](int idx)
    {
//        dbg_assert(idx < size());
        return view_start[idx];
    }
    void operator++()
    {
        view_start++;
    }
    bool end()
    {
        return view_start == view_end;
    }
    operator bool() {
        return !end();
    }
    T& operator *() {
        return operator[](0);
    }
};
