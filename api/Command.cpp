#include <pch.h>
enum XX : int {
	WTF = 1,
	KKSK = 2
};
bool test(CommandOrigin const& ori, CommandOutput& outp, MyEnum<XX>,optional<CommandSelector<Player>>& c) {
	if (c.set) {
		auto res = c.val.results(ori);
		if (!Command::checkHasTargets2(res, outp))
			return false;
		for (auto i : res) {
			outp.addMessage(i->getNameTag());
		}
		return true;
	}
	return false;
}

template <class T>
LIGHTBASE_API T* LocateS<T>::_srv;
THook(void, "?setup@ChangeSettingCommand@@SAXAEAVCommandRegistry@@@Z", CommandRegistry* rg, void* a1) {
	LocateS<CommandRegistry>::assign(*rg);
	addListener([](RegisterCommandEvent&) {
		MakeCommand("testx", "kksk", 0);
		CEnum<XX> enm("wtf", { "a", "b" });
		CmdOverload2(
			testx, test, [](auto& i) { 
				std::get<1>(i).val.setIncludeDeadPlayers(true); 
			}, "a0","a1");
		});
	original(rg, a1);
	RegisterCommandEvent::_call();
	RegisterCommandEvent::_removeall();
}
