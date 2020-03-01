#pragma once
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
		_srv = (T*)&srv;
	}
};
