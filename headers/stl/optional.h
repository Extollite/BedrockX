#pragma once
struct Ioptional {};
template <typename T>
struct optional : Ioptional {
	char filler[sizeof(T)];
	using val = typename T;
	bool set;
	operator bool() {
		return set;
	}
	T& value() {
		if (!set) {
			throw(std::exception("bad optional access"));
		}
		return *(T*)filler;
	}
	const T& value()const {
		if (!set) {
			throw(std::exception("bad optional access"));
		}
		return *(T*)filler;
	}
	bool Set() {
		return set;
	}
	operator T() {
		return value();
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
	optional(const optional<T>& x) {
		set = x.set;
		if (set) {
			new (filler) T(x.value());
		}
	}
	optional(optional<T>&& x) {
		set = x.set;
		if (set) {
			new (filler) T(std::move(x.value()));
		}
		x.set = false;
	}
	optional<T>& operator=(const optional<T>& x) {
		set = x.set;
		if (set) {
			new (filler) T(x.value());
		}
		return x;
	}
};
