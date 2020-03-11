#pragma once
#include "hash.h"
#include "hook.h"
#include "lightbase.h"
template <typename T, int off>
inline T& dAccess(void* ptr) {
	return *(T*)(((uintptr_t)ptr) + off);
}
#define __WEAK __declspec(selectany)
//#define GetServerSymbol(x) dlsym_real(x)
template <CHash>
__WEAK void* __ptr_cache;
template <CHash hash>
inline static void* dlsym_cache(const char* fn) {
	if (!__ptr_cache<hash>) {
		__ptr_cache<hash> = dlsym_real(fn);
		if (!__ptr_cache<hash>) {
			printf("Cant found sym %s\n", fn);
			exit(1);
		}
	}
	return __ptr_cache<hash>;
}
#if 0
template <CHash>
struct DLSYMCACHE {
	static void* ptr;
	inline static void load(const char* fn) {
		if (!ptr) {
			ptr = dlsym_real(fn);
			if (!ptr) {
				printf("Cant found sym %s\n", fn);
				exit(1);
			}
		}
	}
};
template <CHash hs>
void* DLSYMCACHE<hs>::ptr;
#endif
#if 0
template <CHash hash,typename ret, typename... p>
struct __CALL_IMP {
	void* ptr;
	inline __CALL_IMP(const char* fn) {
		ptr = dlsym<hash>(fn);
	}
	ret inline operator()(p... args) {
		return ((ret(*)(p...))ptr)(args...);
	}
};
#endif
#define VA_EXPAND(...) __VA_ARGS__
//#define Call(fn, ret, ...) __CALL_IMP<do_hash(fn), ret, __VA_ARGS__>(fn)
template <CHash hash, typename ret, typename... p>
static inline auto __imp_Call(const char* fn) {
	return ((ret(*)(p...))(dlsym_cache<hash>(fn)));
}
#define Call(fn, ret, ...) (__imp_Call<do_hash(fn), ret, __VA_ARGS__>(fn))
#define SYM(fn) (dlsym_cache<do_hash(fn)>(fn))
#define dlsym(xx) SYM(xx)
class THookRegister {
public:
	THookRegister(void* address, void* hook, void** org) {
		auto ret = HookFunction(address, org, hook);
		if (ret != 0) {
			std::cerr << "FailedToHook: " << address << std::endl;
		}
	}
	THookRegister(char const* sym, void* hook, void** org) {
		auto found = dlsym_real(sym);
		if (found == nullptr) {
			std::cerr << "SymbolNotFound: " << sym << std::endl;
		}
		auto ret = HookFunction(found, org, hook);
		if (ret != 0) {
			std::cerr << "FailedToHook: " << sym << std::endl;
		}
	}
	template <typename T>
	THookRegister(const char* sym, T hook, void** org) {
		union {
			T a;
			void* b;
		} hookUnion;
		hookUnion.a = hook;
		THookRegister(sym, hookUnion.b, org);
	}
	template <typename T>
	THookRegister(void* sym, T hook, void** org) {
		union {
			T a;
			void* b;
		} hookUnion;
		hookUnion.a = hook;
		THookRegister(sym, hookUnion.b, org);
	}
};
#define VA_EXPAND(...) __VA_ARGS__
template <CHash>
struct THookTemplate;
template <CHash>
extern THookRegister THookRegisterTemplate;

#define _TInstanceHook(class_inh, pclass, iname, sym, ret, ...)                                             \
	template <>                                                                                             \
	struct THookTemplate<do_hash(iname)> class_inh {                                                        \
		typedef ret (THookTemplate::*original_type)(__VA_ARGS__);                                           \
		static original_type& _original() {                                                                 \
			static original_type storage;                                                                   \
			return storage;                                                                                 \
		}                                                                                                   \
		template <typename... Params>                                                                       \
		static ret original(pclass* _this, Params&&... params) {                                            \
			return (((THookTemplate*)_this)->*_original())(std::forward<Params>(params)...);                \
		}                                                                                                   \
		ret _hook(__VA_ARGS__);                                                                             \
	};                                                                                                      \
	template <>                                                                                             \
	static THookRegister THookRegisterTemplate<do_hash(iname)>{ sym, &THookTemplate<do_hash(iname)>::_hook, \
		(void**)&THookTemplate<do_hash(iname)>::_original() };                                              \
	ret THookTemplate<do_hash(iname)>::_hook(__VA_ARGS__)

#define _TInstanceDefHook(iname, sym, ret, type, ...) \
	_TInstanceHook(                                   \
		: public type, type, iname, sym, ret, VA_EXPAND(__VA_ARGS__))
#define _TInstanceNoDefHook(iname, sym, ret, ...) _TInstanceHook(, void, iname, sym, ret, VA_EXPAND(__VA_ARGS__))

#define _TStaticHook(pclass, iname, sym, ret, ...)                                                          \
	template <>                                                                                             \
	struct THookTemplate<do_hash(iname)> pclass {                                                           \
		typedef ret (*original_type)(__VA_ARGS__);                                                          \
		static original_type& _original() {                                                                 \
			static original_type storage;                                                                   \
			return storage;                                                                                 \
		}                                                                                                   \
		template <typename... Params>                                                                       \
		static ret original(Params&&... params) {                                                           \
			return _original()(std::forward<Params>(params)...);                                            \
		}                                                                                                   \
		static ret _hook(__VA_ARGS__);                                                                      \
	};                                                                                                      \
	template <>                                                                                             \
	static THookRegister THookRegisterTemplate<do_hash(iname)>{ sym, &THookTemplate<do_hash(iname)>::_hook, \
		(void**)&THookTemplate<do_hash(iname)>::_original() };                                              \
	ret THookTemplate<do_hash(iname)>::_hook(__VA_ARGS__)

#define _TStaticDefHook(iname, sym, ret, type, ...) \
	_TStaticHook(                                   \
		: public type, iname, sym, ret, VA_EXPAND(__VA_ARGS__))
#define _TStaticNoDefHook(iname, sym, ret, ...) _TStaticHook(, iname, sym, ret, VA_EXPAND(__VA_ARGS__))

#define THook2(iname, ret, sym, ...) _TStaticNoDefHook(iname, sym, ret, VA_EXPAND(__VA_ARGS__))
#define THook(ret, sym, ...) THook2(sym, ret, sym, VA_EXPAND(__VA_ARGS__))
#define TStaticHook2(iname, ret, sym, type, ...) _TStaticDefHook(iname, sym, ret, type, VA_EXPAND(__VA_ARGS__))
#define TStaticHook(ret, sym, type, ...) TStaticHook2(sym, ret, sym, type, VA_EXPAND(__VA_ARGS__))
#define TClasslessInstanceHook2(iname, ret, sym, ...) _TInstanceNoDefHook(iname, sym, ret, VA_EXPAND(__VA_ARGS__))
#define TClasslessInstanceHook(ret, sym, ...) TClasslessInstanceHook2(sym, ret, sym, VA_EXPAND(__VA_ARGS__))
#define TInstanceHook2(iname, ret, sym, type, ...) _TInstanceDefHook(iname, sym, ret, type, VA_EXPAND(__VA_ARGS__))
#define TInstanceHook(ret, sym, type, ...) TInstanceHook2(sym, ret, sym, type, VA_EXPAND(__VA_ARGS__))