#pragma once
struct Ioptional {};
template <typename T>
struct optional : Ioptional {
	char filler[sizeof(T)];
	using val = typename T;
	bool set;
	T& value() {
		if (!set) {
			throw(std::exception("bad optional access"));
		}
		return *(T*)filler;
	}
	operator bool() {
		return set;
	}
	optional(T const& v) {
		new (filler) T(v);
		set = true;
	}
	optional(T&& v) {
		new (filler) T(std::forward<T>(v));
		set = true;
	}
	optional() {
		set = false;
	}
	optional(optional<T> const& x) {
		set = x.set;
		if (set) {
			new (filler) T(x.val());
		}
	}
	optional(optional<T>&& x) {
		set = x.set;
		if (set) {
			new (filler) T(std::move(x.val()));
		}
		x.set = false;
	}
};
