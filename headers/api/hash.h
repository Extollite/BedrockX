#pragma once
#define BKDR_MUL 97
#define BKDR_ADD 0
typedef unsigned long long CHash;
constexpr CHash do_hash(const char* x,size_t sz) {
	CHash rval = 0;
	for (int i = 0; i < sz; ++i) {
		rval *= BKDR_MUL;
		rval += x[i];
		rval += BKDR_ADD;
	}
	return rval;
}
constexpr CHash do_hash(const char* x) {
	CHash rval = 0;
	for (int i = 0; x[i]; ++i) {
		rval *= BKDR_MUL;
		rval += x[i];
		rval += BKDR_ADD;
	}
	return rval;
}