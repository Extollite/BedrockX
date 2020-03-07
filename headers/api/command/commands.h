#pragma once
#include<array>
#include <mcapi/Command/CommandReg.h>
#include <type_traits>
#include<string>
using std::string;

namespace CMDREG {
	template <typename T>
	inline typeid_t<CommandRegistry> getTPID();
	inline typeid_t<CommandRegistry>& GETID(const char* name) {
		return *(typeid_t<CommandRegistry>*)(GetServerSymbol(name));
	}
	inline typeid_t<CommandRegistry> ALLOCID() {
		auto& id = *((unsigned short*)GetServerSymbol("?count@?$typeid_t@VCommandRegistry@@@@2GA"));
		return { id++ };
	}

	template <>
	inline typeid_t<CommandRegistry> getTPID<bool>() {
		return GETID("?id@?1???$type_id@VCommandRegistry@@_N@@YA?AV?$typeid_t@VCommandRegistry@@@@XZ@4V1@A");
	}
	template <>
	inline typeid_t<CommandRegistry> getTPID<int>() {
		return GETID("?id@?1???$type_id@VCommandRegistry@@H@@YA?AV?$typeid_t@VCommandRegistry@@@@XZ@4V1@A");
	}
	template <>
	inline typeid_t<CommandRegistry> getTPID<float>() {
		return GETID("?id@?1???$type_id@VCommandRegistry@@M@@YA?AV?$typeid_t@VCommandRegistry@@@@XZ@4V1@A");
	}
	template <>
	inline typeid_t<CommandRegistry> getTPID<std::string>() {
		return GETID(
			"?id@?1???$type_id@VCommandRegistry@@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@@YA?AV?$"
			"typeid_t@VCommandRegistry@@@@XZ@4V1@A");
	}
	template <>
	inline typeid_t<CommandRegistry> getTPID<CommandSelector<Actor>>() {
		return GETID(
			"?id@?1???$type_id@VCommandRegistry@@V?$CommandSelector@VActor@@@@@@YA?AV?$typeid_t@VCommandRegistry@@@@XZ@4V1@"
			"A");
	}
	template <>
	inline typeid_t<CommandRegistry> getTPID<CommandSelector<Player>>() {
		return GETID(
			"?id@?1???$type_id@VCommandRegistry@@V?$CommandSelector@VPlayer@@@@@@YA?AV?$typeid_t@VCommandRegistry@@@@XZ@4V1@"
			"A");
	}
	template <typename T>
	class CEnum {
	public:
		static typeid_t<CommandRegistry> myid;
		static string name;
		CEnum(string const& nam, std::initializer_list<std::string> const& values) {
			name = nam;
			if (myid.value == 65535) {
				myid = ALLOCID();
				LocateS<CommandRegistry>()->addEnumValues(name, myid, values);
			}
		}
	};
	template <typename T>
	typeid_t<CommandRegistry> CEnum<T>::myid(65535);
	template <typename T>
	string CEnum<T>::name;

	struct Ioptional {};
	struct IMyEnum {};
	template <typename T>
	struct optional : Ioptional {
		T val;
		bool set;
	};
	template <typename E>
	struct MyEnum : IMyEnum {
		E val;
	};

	class MakeCommand {
	public:
		MakeCommand(string const& name, const char* desc, int lvl) {
			LocateS<CommandRegistry>()->registerCommand(name, desc, (CommandPermissionLevel)lvl, { CommandFlagValue(0) }, { CommandFlagValue(72) });
		}
	};

	template <typename T>
	typeid_t<CommandRegistry> typeid_getter() {
		if constexpr (std::is_base_of_v<IMyEnum, T>) {
			return CEnum<decltype(T::val)>::myid;
		}
		else {
			if constexpr (std::is_base_of_v<Ioptional, T>) {
				return typeid_getter<decltype(T::val)>();
			}
			else {
				return getTPID<T>();
			}
		}
	}
	template <typename Dummy, typename... TP>
	class MakeOverload {
		using container = std::tuple<std::remove_reference_t<TP>...>;

	public:
		class sub : public Command {
		public:
			container data;
			static uintptr_t cb;
			template <std::size_t... Index>
			inline bool invoke_impl(CommandOrigin const& a, CommandOutput& b, std::index_sequence<Index...>) {
				return ((bool (*)(CommandOrigin const&, CommandOutput&, TP...))cb)(a, b, std::get<Index>(data)...);
			}
			void execute(CommandOrigin const& a, CommandOutput& b) {
				constexpr auto size = std::tuple_size<container>::value;
				if (invoke_impl(a, b, std::make_index_sequence<size>{}))
					b.success();
			}
			sub() {}
		};
		std::vector<CommandParameterData> vc;
		std::vector<string> argn;
		static std::function<void(container&)> new_cb;
		template <typename TX>
		inline void reg_impl_sub(uintptr_t off, string const& desc) {
			off += offsetof(sub, data);
			if constexpr (std::is_base_of_v<Ioptional, TX>) {
				using TXX = decltype(TX::val);
				if constexpr (std::is_base_of_v<IMyEnum, TXX>) {
					vc.emplace_back(typeid_getter<TXX>(), &CommandRegistry::parseEnumInt, desc, CommandParameterDataType::ENUM, CEnum<decltype(TXX::val)>::name.c_str(), int(off + offsetof(TX, val) + offsetof(TXX, val)), true, int(off + offsetof(TX, set)));
				}
				else {
					vc.emplace_back(typeid_getter<TXX>(), CommandRegistry::getParseFn<TXX>(), desc, CommandParameterDataType::NORMAL, nullptr, int(off + offsetof(TX, val)), true, int(off + offsetof(TX, set)));
				}
			}
			else {
				if constexpr (std::is_base_of_v<IMyEnum, TX>) {
					vc.emplace_back(typeid_getter<TX>(), &CommandRegistry::parseEnumInt, desc, CommandParameterDataType::ENUM, CEnum<decltype(TX::val)>::name.c_str(), int(off + offsetof(TX, val)), false, -1);
				}
				else {
					vc.emplace_back(typeid_getter<TX>(), CommandRegistry::getParseFn<TX>(), desc, CommandParameterDataType::NORMAL, nullptr, int(off), false, -1);
				}
			}
		}
		template <std::size_t... Index>
		inline void reg_helper(std::index_sequence<Index...>) {
			container& cter = *(container*)0;
			(reg_impl_sub<std::remove_reference_t<decltype(std::get<Index>(cter))>>((uintptr_t)std::addressof(std::get<Index>(cter)) - (uintptr_t)std::addressof(cter), argn[Index]), ...);
		}
		void regMe(string const& cname) {
			LocateS<CommandRegistry>()->registerOverload(cname, &factory, vc);
		}
		template <typename... TP2>
		MakeOverload(Dummy*, std::function<void(container&)>&& _new_cb, string const& cname, bool (*__cb)(CommandOrigin const&, CommandOutput&, TP...), TP2... argns) {
			static_assert(sizeof...(TP2) == sizeof...(TP));
			new_cb = std::forward<decltype(new_cb)>(_new_cb);
			sub::cb = (decltype(sub::cb))__cb;
			(argn.emplace_back(argns), ...);
			static_assert(sizeof...(TP2) == sizeof...(TP));
			constexpr auto size = std::tuple_size<container>::value;
			reg_helper(std::make_index_sequence<size>{});
			regMe(cname);
		}
		template <typename... TP2>
		MakeOverload(Dummy*, string const& cname, bool (*__cb)(CommandOrigin const&, CommandOutput&, TP...), TP2... argns) {
			static_assert(sizeof...(TP2) == sizeof...(TP));
			sub::cb = (decltype(sub::cb))__cb;
			(argn.emplace_back(argns), ...);
			constexpr auto size = std::tuple_size<container>::value;
			reg_helper(std::make_index_sequence<size>{});
			regMe(cname);
		}
		static std::unique_ptr<Command> factory() {
			auto rv = std::make_unique<sub>();
			new_cb(rv->data);
			return rv;
		}
	};
	template <typename Dummy, typename... TP>
	uintptr_t MakeOverload<Dummy, TP...>::sub::cb;
	template <typename Dummy, typename... TP>
	std::function<void(std::tuple<std::remove_reference_t<TP>...>&)> MakeOverload<Dummy, TP...>::new_cb = [](auto&) {};
};
using CMDREG::CEnum, CMDREG::MakeCommand, CMDREG::MakeOverload, CMDREG::MyEnum, CMDREG::optional;

#define CmdOverload(name2, cb, ...) \
	{ MakeOverload __ov1((struct name2*)0, #name2, cb, __VA_ARGS__); }
#define CmdOverload2(name2, cb, cb2, ...) \
	{ MakeOverload __ov2((struct name2*)0, cb2, #name2, cb, __VA_ARGS__); }
