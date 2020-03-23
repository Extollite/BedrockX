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
	void clear() {
		while (!empty()) pop_back();
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
	struct iterator {
		static_queue& thi;
		size_t now;
		bool operator==(const iterator& x) const{
			return now == x.now;
		}
		bool operator!=(const iterator& x) const {
			return now!=x.now;
		}
		T& operator->() {
			return thi[now];
		}
		T& operator*() {
			return thi[now];
		}
		void operator++() {
			now++;
		}
	};
	iterator begin() {
		return { *this,0 };
	}
	iterator end() {
		return { *this,size() };
	}
};