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
	static void assign(const T& srv) {
		_srv = (T*)&srv;
	}
};
template<class T>
LIGHTBASE_API T* LocateS<T>::_srv;