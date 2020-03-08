#pragma once
#include <string>
#include <string_view>
#include <memory>
#include <vector>
#include "Command.h"


template <typename T>
class typeid_t {
public:
	unsigned short value;

	typeid_t(typeid_t const& id) : value(id.value) {}
	typeid_t(unsigned short value) : value(value) {}
};
enum CommandPermissionLevel{ 
	Normal = 0,
	Privileged = 1,
	AutomationPlayer = 2,
	OperatorOnly = 3,
	ConsoleOnly = 4 };

class CommandVersion {
public:
	int min, max;
	inline CommandVersion() : min(1), max(0x7FFFFFFF) {}
	inline CommandVersion(int min, int max) : min(min), max(max) {}
	static __declspec(dllimport) int const CurrentVersion;
};

class Command {
protected:
	int unk8;		   // 8
	void* unk16;	   // 16
	int unk24;		   // 24
	unsigned char b28; // 28
	CommandFlag flag;  // 29
	Command() {
		unk24 = -1;
		b28 = 5;
	}

public:
	__declspec(dllimport) virtual ~Command();
	virtual void execute(CommandOrigin const&, CommandOutput&) = 0;
	template <typename T>
	static bool checkHasTargets2(CommandSelectorResults<T> const& a, CommandOutput& b) {
		return checkHasTargets(a, b);
	}
protected:
	//??$checkHasTargets@VActor@@@Command@@KA_NAEBV?$CommandSelectorResults@VActor@@@@AEAVCommandOutput@@@Z
	template <typename T>
	__declspec(dllimport) static bool checkHasTargets(CommandSelectorResults<T> const&, CommandOutput&);
};
enum class CommandParameterDataType { NORMAL,
	ENUM,
	SOFT_ENUM };
class CommandRegistry;
struct CommandParameterData;
class CommandRegistry {
public:
#pragma region struct
	struct ParseToken;
	class Symbol {
	public:
		unsigned val;
	};
	struct Overload {
		using FactoryFn = std::unique_ptr<Command> (*)(void);
		CommandVersion version;					  // 0
		FactoryFn factory;						  // 8
		std::vector<CommandParameterData> params; // 16
		unsigned char unk;						  // 40
		inline Overload(CommandVersion version, FactoryFn factory, std::vector<CommandParameterData>&& args)
			: version(version), factory(factory), params(std::forward< std::vector<CommandParameterData>>(args)), unk(255) {}
	};
	struct Signature {
		std::string name;								  // 0
		std::string desc;								  // 32
		std::vector<CommandRegistry::Overload> overloads; // 64
		CommandPermissionLevel perm;					  // 88
		CommandRegistry::Symbol main_symbol;			  // 92
		CommandRegistry::Symbol alt_symbol;				  // 96
		CommandFlag flag;								  // 100
		int unk72;
		int unk76;
		int unk80;
		bool b84;

		inline Signature(
			std::string_view name, std::string_view desc, CommandPermissionLevel perm, CommandRegistry::Symbol symbol,
			CommandFlag flag)
			: name(name), desc(desc), perm(perm), main_symbol(symbol), flag(flag) {}
	};

	struct SoftEnum {
		std::string name;			   // 0
		std::vector<std::string> list; // 32
	};
#pragma endregion struct definition

	__declspec(dllimport) void registerCommand(
		std::string const&, char const*, CommandPermissionLevel, CommandFlag, CommandFlag);
	__declspec(dllimport) void registerAlias(std::string const&, std::string const&);

private:
	__declspec(dllimport) Signature const* findCommand(std::string const&) const;
	__declspec(dllimport) void registerOverloadInternal(Signature&, Overload&);

	template <typename Type>
	__declspec(dllimport) bool parse(
		void*, ParseToken const&, CommandOrigin const&, int, std::string&, std::vector<std::string>&) const;

	__declspec(dllimport) Symbol addEnumValuesInternal(
		std::string const&, std::vector<std::pair<std::string, uint64_t>> const&, typeid_t<CommandRegistry>,
		bool (CommandRegistry::*)(
			void*, CommandRegistry::ParseToken const&, CommandOrigin const&, int, std::string&,
			std::vector<std::string>&) const);
	__declspec(dllimport) unsigned addEnumValues(std::string const&, std::vector<std::string> const&);
	__declspec(dllimport) uint64_t getEnumData(CommandRegistry::ParseToken const&) const;

public:
	template <typename T>
	inline static auto getParseFn() { return &CommandRegistry::parse<T>; }

	template <typename Type>
	bool
	fakeparse(void*, ParseToken const&, CommandOrigin const&, int, std::string&, std::vector<std::string>&) const {
		return false;
	}
	bool parseEnumInt(
		void* target, CommandRegistry::ParseToken const& token, CommandOrigin const&, int, std::string&,
		std::vector<std::string>&) const {
		auto data = getEnumData(token);
		*(int*)target = (int)data;
		return true;
	}

	template <typename Type>
	unsigned addEnumValues(
		std::string const& name, typeid_t<CommandRegistry> tid,
		std::initializer_list<std::pair<std::string, Type>> const& values) {
		std::vector<std::pair<std::string, uint64_t>> converted;
		for (auto& value : values)
			converted.emplace_back(value.first, (uint64_t)value.second);
		return addEnumValuesInternal(name, converted, tid, &CommandRegistry::parseEnumInt).val;
	}
	unsigned addEnumValues(
		std::string const& name, typeid_t<CommandRegistry> tid,
		std::initializer_list<std::string> const& values) {
		std::vector<std::pair<std::string, uint64_t>> converted;
		uint64_t idx = 0;
		for (auto& value : values)
			converted.emplace_back(value, ++idx);
		return addEnumValuesInternal(name, converted, tid, &CommandRegistry::parseEnumInt).val;
	}
	inline void registerOverload(
		std::string const& name, Overload::FactoryFn factory, std::vector<CommandParameterData>&& args) {
		Signature* signature = const_cast<Signature*>(findCommand(name));
		auto& overload = signature->overloads.emplace_back(CommandVersion{}, factory, std::forward<std::vector<CommandParameterData>>(args));
		registerOverloadInternal(*signature, overload);
	}
};

struct CommandParameterData {
	using ParseFn = bool (CommandRegistry::*)(
		void*, CommandRegistry::ParseToken const&, CommandOrigin const&, int, std::string&,
		std::vector<std::string>&) const;
	typeid_t<CommandRegistry> tid; // 0
	ParseFn parser;				   // 8
	std::string name;			   // 16
	char const* desc;			   // 48
	int unk56;					   // 56
	CommandParameterDataType type; // 60
	int offset;					   // 64
	int flag_offset;			   // 68
	bool mand;					   // 72
	bool pad73;					   // 73
	CommandParameterData():tid(0) {}
	CommandParameterData(
		typeid_t<CommandRegistry> tid, ParseFn parser, std::string_view desc_, CommandParameterDataType type,
		char const* enumname, int offset, bool optional, int flag_offset)
		: tid(tid), parser(parser), name(desc_), desc(enumname), unk56(-1), type(type), offset(offset),
		  flag_offset(flag_offset), mand(optional),pad73(false) {}
};
static_assert(offsetof(CommandParameterData, pad73) == 73);
static_assert(offsetof(CommandParameterData, name) == 16);
static_assert(offsetof(CommandParameterData, unk56) == 56);
