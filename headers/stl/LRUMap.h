#pragma once
#include<type_traits>
template <typename _TP, bool HEAD = false>
struct List_node {
	List_node<_TP, false>*prev, *next;
	using TP = typename std::conditional<HEAD, int, _TP>::type;
	TP val;
	TP& get() {
		return val;
	}
	TP const& get() const {
		return val;
	}
	List_node() {
		prev = next = (List_node<_TP, false>*)this;
	}
	List_node(TP&& x) : val(std::forward<TP>(x)) {
		prev = next = (List_node<_TP, false>*)this;
	}
	List_node(TP const& x) : val(x) {
		prev = next = (List_node<_TP, false>*)this;
	}
	~List_node() {
		detach();
	}
	void detach() {
		prev->next = next;
		next->prev = prev;
	}
#if 0
	struct iterator {
		List_node<_TP>* val;
		void operator++() {
			val = val->next;
		}
		void operator--() {
			val = val->prev;
		}
		List_node<_TP>& operator*() {
			return *val;
		}
		bool operator!=(iterator const& x) {
			return val != x.val;
		}
		bool operator==(iterator const& x) {
			return val == x.val;
		}
	};
	iterator begin() {
		return iterator{ this->next };
	}
	iterator end() {
		return iterator{ (List_node<_TP, false>*)this };
	}
#endif
	void ins_back(List_node<_TP>& t) {
		t.next = next;
		t.prev = (List_node<_TP, false>*)this;
		next->prev = &t;
		next = &t;
	}
	void ins_front(List_node<_TP>& t) {
		t.prev = prev;
		t.next = (List_node<_TP, false>*)this;
		prev->next = &t;
		prev = &t;
	}
	size_t _size() {
		size_t rv = 0;
		auto now = next;
		while (now != (List_node<_TP, false>*)this) {
			rv++;
			now = now->next;
		}
		return rv;
	}
};
template <typename TP>
struct LRUList {
	size_t sz;
	using node = List_node<TP>;
	List_node<TP, true> head;
	node* data;
	LRUList(size_t _sz) : sz(_sz) {
		data = new node[_sz]();
		for (int i = 0; i < _sz; ++i) {
			head.ins_front(data[i]);
		}
	}
	~LRUList() {
		delete[] data;
	}
	auto begin() {
		return head.begin();
	}
	auto end() {
		return head.end();
	}
	TP& buy() {
		auto it = head.prev;
		it->detach();
		head.ins_back(*it);
		return it->get();
	}
};
template <typename TP, size_t buksz = 64>
struct U64LRUmap {
	using key_t = uint64_t;
	struct _P {
		TP val;
		key_t hash;
	};
	using node = List_node<_P>;
	List_node<_P, true> bucket[buksz];
	LRUList<node> alloc;
	U64LRUmap(size_t sz) : alloc(sz) {}
	void clear() {
		for (int i = 0; i < buksz; ++i) {
			List_node<_P, false>* END = (List_node<_P, false> *)&bucket[i];
			auto NOW=bucket[i].next;
			while(NOW!=END) {
				auto NEXT = NOW->next;
				NOW->detach();
				NOW->val.val.~TP();
				new (&NOW->val.val) TP();
				NOW = NEXT;
			}
		}
	}
	size_t _size() {
		size_t rv;
		for (int i = 0; i < buksz; ++i) {
			rv += bucket[i]._size();
		}
		return rv;
	}
	TP* find(key_t key) {
		auto& bk = bucket[key % buksz];
		auto NOW = bk.next;
		auto END = (decltype(NOW))&bk;
		while (NOW!=END)
		{
				if (NOW->val.hash == key) {
					NOW->detach();
					bk.ins_back(*NOW);
					return &NOW->val.val;
				}
				NOW = NOW->next;
		} 
		return nullptr;
	}
	template <typename... P>
	TP* insert(key_t key, P&&... val) {
		auto& bk = bucket[key % buksz];
		auto& nd = alloc.buy();
		nd.detach();
		nd.val.hash = key;
		nd.val.val.~TP();
		new (&nd.val.val) TP(std::forward<P>(val)...);
		bk.ins_back(nd);
		return &nd.val.val;
	}
};