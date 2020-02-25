#pragma once
#include<string_view>
template<typename T=int>
constexpr T atoi(std::string_view sv) {
    T res = 0;
    int fg = 0;
    const char* c = sv.data();
    auto sz = sv.size();
    for (decltype(sz) i = 0; i < sz; ++i) {
        if (c[i] == '-') { fg = 1; }
        if (!(c[i] >= '0' && c[i] <= '9')) continue;
        res *= 10;
        res += c[i] - '0';
    }
    return fg ? -res : res;
}