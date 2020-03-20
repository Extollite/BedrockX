#pragma once
#include<api\lightbase.h>
template<class T>
struct LocateS {
	LIGHTBASE_API static T* _srv;
	T& operator*() {
		return *_srv;
	}
	T* operator->() {
		return _srv;
	}
	operator T& () {
		return *_srv;
	}
	static void assign(const T& srv) {
		printf("[LocateService] located %s -> %p\n", typeid(decltype(_srv)).name(), &srv);
		_srv = (T*)&srv;
	}
};
