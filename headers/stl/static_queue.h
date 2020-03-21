#pragma once
#include"views.h"
template<typename T,size_t CAP=256>
class static_queue {
	char data[sizeof(T) * CAP];
	size_t count;
public:
	static_queue() {
		count = 0;
	}
	size_t size() {
		return count;
	}
	bool empty() {
		return size() == 0;
	}
	bool full() {
		return size() == CAP;
	}
	template<typename... P>
	T& emplace_back(P&&... arg) {
		T* dst = (T*)(data + count*sizeof(T));
		new (dst) T(std::forward<P>(arg)...);
		count++;
		return *dst;
	}
	void push_back(T& arg) {
		T* dst = (T*)(data + count * sizeof(T));
		count++;
		new(dst)T(arg);
	}
	T& front() {
		return *(T*)data;
	}
	T& back() {
		T* dst = (T*)(data + (count-1) * sizeof(T));
		return *dst;
	}
	void pop_back() {
		T& bk = back();
		bk.~T();
		count--;
	}
	T& operator[](size_t idx) {
		return *(T*)(data + idx * sizeof(T));
	}
	array_view<T> asView() {
		return {(T*)data,((T*)data)+count};
	}
	operator array_view<T>() {
		return asView();
	}
};