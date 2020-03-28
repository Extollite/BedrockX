#pragma once
#include <tuple>
#include <string_view>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iostream>
using std::string_view;
struct stdio_commit {
	string_view prefix;
	void operator()(string_view extra, string_view content) const {
		std::cout << extra << prefix << content << '\n';
	}
	stdio_commit(string_view prefix_) : prefix(prefix_) {

	}
};
struct file_commit {
	std::ofstream dat;
	file_commit(const char* fn) : dat(fn, std::ios::app) {
	}
	void operator()(string_view extra, string_view content) {
		dat << extra;
		dat << content << "\n";
	}
};
template <typename... TP>
struct stacked {
	std::tuple<TP...> data;
	stacked(TP&&... args) noexcept : data{ std::forward<TP>(args)... } {}
	template <size_t idx, typename... TC>
	void _call(TC&&... args) noexcept {
		std::get<idx>(data)(std::forward<TC>(args)...);
		if constexpr (idx != std::tuple_size_v<decltype(data)> - 1) {
			_call<idx + 1, TC...>(std::forward<TC>(args)...);
		}
	}
	template <typename... TC>
	void operator()(TC&&... args) noexcept {
		_call<0, TC...>(std::forward<TC>(args)...);
	}
};
enum class LOGLVL : char {
	Debug = 0,
	Info = 1,
	Error = 2,
	Fatal = 3
};

template <typename COMMITER>
struct Logger {
	COMMITER cmt;
	LOGLVL lvlmin;
	static constexpr string_view LVLNAME[4] = { "DEBUG]", "INFO]", "ERROR]", "FATAL]" };
	Logger(COMMITER&& cm) : cmt(std::forward<COMMITER>(cm)) {
		lvlmin = LOGLVL::Info;
	}
	template <typename A, typename B>
	static inline void __helper(A& x, B&& y) {
		x << std::forward<B>(y);
	}
	template <typename A, typename B>
	static inline void __helper(A& x, B&& y, char z) {
		x << std::forward<B>(y) << z;
	}
	template <LOGLVL lvl, char delim = 0, typename... TP>
	void _logimpl(TP&&... args) {
		char datebuf[256];
		struct tm _tim;
		{
			auto timnow = time(0);
			localtime_s(&_tim, &timnow);
		}
		auto timsz = strftime(datebuf, 256, "[%Y-%m-%d %H:%M:%S ", &_tim);
		strcat_s(datebuf, LVLNAME[int(lvl)].data());
		std::stringstream ss;
		if constexpr (delim != 0) {
			(__helper(ss, std::forward<TP>(args), delim), ...);
		}
		else {
			(__helper(ss, std::forward<TP>(args)), ...);
		}
		cmt(string_view{ datebuf, timsz + LVLNAME[int(lvl)].size() }, ss.str()); //level time ss
	}
	template <LOGLVL lvl = LOGLVL::Info, typename... TP>
	void l(TP&&... args) {
		if (lvl >= lvlmin) {
			_logimpl<lvl>(std::forward<TP>(args)...);
		}
	}
	template <typename... TP>
	void operator()(TP&&... args) {
		p(std::forward<TP>(args)...);
	}
	template <LOGLVL lvl = LOGLVL::Info, char join = ' ', typename... TP>
	void p(TP&&... args) {
		if (lvl >= lvlmin) {
			_logimpl<lvl, join>(std::forward<TP>(args)...);
		}
	}
};