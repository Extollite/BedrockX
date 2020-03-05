#pragma once
struct MCRESULT {
	unsigned char filler[4];
	operator bool() {
		return filler[0];
	}
	bool isSuccess() {
		return operator bool();
	}
};
class MinecraftCommands {
public:
	static MCRESULT _runcmd(void* origin, string const& cmd, int unk1, bool unk2) {
		MCRESULT rv;
		Call("?requestCommandExecution@MinecraftCommands@@QEBA?AUMCRESULT@@V?$unique_ptr@VCommandOrigin@@U?$default_delete@VCommandOrigin@@@std@@@std@@AEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@4@H_N@Z", void, MinecraftCommands*, MCRESULT*, void**, string const&, int, bool)(LocateS<MinecraftCommands>()._srv, &rv, &origin, cmd, unk1, unk2);
		return rv;
	}
};
class RakNetServerLocator {
public:
	MCINLINE void accounce(class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& a, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const& b, int c_type, int d, int e, bool f) {
		Call("?announceServer@RakNetServerLocator@@UEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@0W4GameType@@HH_N@Z", void, void*, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&, int, int, int, bool)(this, a, b, c_type, d, e, f);
	}
};