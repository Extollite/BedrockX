#pragma once
#define BKDR_MUL 97
#define BKDR_ADD 0
#define BKDR_MUL2 19260817
#define BKDR_ADD2 1
typedef unsigned long long CHash;
constexpr CHash do_hash(const char* x, size_t sz) {
	CHash rval = 0;
	for (size_t i = 0; i < sz; ++i) {
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
constexpr CHash do_hash2(const char* x, size_t sz) {
	CHash rval = 0;
	for (size_t i = 0; i < sz; ++i) {
		rval *= BKDR_MUL2;
		rval += x[i];
		rval += BKDR_ADD2;
	}
	return rval;
}
constexpr CHash do_hash2(const char* x) {
	CHash rval = 0;
	for (int i = 0; x[i]; ++i) {
		rval *= BKDR_MUL2;
		rval += x[i];
		rval += BKDR_ADD2;
	}
	return rval;
}