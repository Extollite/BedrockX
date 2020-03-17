// LightBase.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include <api/gui/gui.h>
#include <filesystem>
#include "framework.h"
/*
THook(
	void,
	"?registerCommand@CommandRegistry@@QEAAXAEBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@"
	"PEBDW4CommandPermissionLevel@@UCommandFlag@@3@Z",
	uintptr_t a0, uintptr_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uintptr_t a5) {
	original(a0, a1, a2, a3, a4, 0x40);
}
THook(
	void**,
	"?getEncryptedPeerForUser@NetworkHandler@@QEAA?AV?$weak_ptr@VEncryptedNetworkPeer@@@std@@AEBVNetworkIdentifier@@@Z",
	void* a, void** b, void* c) {
	b[0] = b[1] = NULL;
	return b;
}*/
/*
void sometest() {
	addListener(
		[](PlayerJoinEvent& ev) {
			//printf("barrier\n");
			//printf("listen %s %d\n", ev.getPlayer().getName().c_str(), ev.getPlayer()->getCarriedItem().getId());
			auto sp = ev.getPlayer();
			LocateS<MainHandler>()->schedule(DelayedTask([sp]() {
				printf("add %d\n", sp.v->getCarriedItem().getId());
				LocateS<WLevel>()->broadcastText("114514");
				printf("dim %p %p\n", WActor(*sp.v).getDim().v, LocateS<ServerLevel>()->getDimension(0));
				WPlayer wp(*sp.v);
				printf("ename %s\n", ExtendedCertificate::getIdentityName(*wp._getCert()).c_str());
				printf("cmd %d\n", BDX::runcmd("help 3"));
				printf("asplayer %d\n", BDX::runcmdAs(wp, "me kksk"));
				printf("asplayer2 %d\n", BDX::runcmdAs(wp, "op kksk"));
				wp.teleport({ 114, 514, 1919 }, 0);
				xuid_t xuid = wp.getXuid();
				std::cout << xuid << std::endl;
				LocateS<MainHandler>()->schedule(RepeatingTask([sp](){
					//sp.v->kill();
					WPlayer wp = sp;
					wp.getDim().setBlock(int(wp->getPos().x), int(wp->getPos().y), int(wp->getPos().z),VanillaBlocks::DiamondBlock());
				},2));
			},
				2));
			using namespace GUI;
			auto sf = std::make_shared<FullForm>();
			sf->addWidget(GUIDropdown("114514", { "kksk", "1919810" }, 1));
			sf->addWidget(GUIInput("wtfwtf", "1919810"));
			sf->addWidget(GUISlider("sss", 1, 100));
			sf->addWidget(GUIToggle("xxx"));
			sf->addWidget(GUILabel("label"));
			sendForm(ev.getPlayer(), FormBinder(sf, function([](ServerPlayer& sp, FullForm& sf, string_view x) {
				std::array<variant<string, int>, 5> ar;
				auto v = parseFormResult(x, ar);
				if (v)
					for (auto& i : ar) {
						std::visit([](auto& vv) { std::cout << vv << std::endl; }, i);
					}
				else
					printf("close\n");
			})));
		});
}

	addListener(function([](ServerStartedEvent& ev) {
		printf("server started\n");
		LocateS<MainHandler>()->schedule(RepeatingTask([]() {
			char buf[1024];
			auto tm__ = time(NULL);
			tm tm2;
			localtime_s(&tm2, &tm__);
			strftime(buf, 1024, "motd: time %H:%M:%S", &tm2);
			LocateS<RakNetServerLocator>()->accounce(buf, "kksk", 0, 114514, 1919810, true);
		},
			2));
	}));
*/
void PrintErrorMessage() {
	DWORD errorMessageID = ::GetLastError();
	if (errorMessageID == 0) {
		std::wcerr << "wtf\n";
		return;
	}
	std::wcerr << errorMessageID << std::endl;
	LPWSTR messageBuffer = nullptr;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, errorMessageID,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR)&messageBuffer, 0, NULL);
	std::wcerr << messageBuffer << std::endl;
	LocalFree(messageBuffer);
}

static void loadall() {
	do_log(L"BedrockX Loaded!\n");
	using namespace std::filesystem;
	create_directory("bdxmod");
	create_directory("data");
	directory_iterator ent("bdxmod");
	for (auto& i : ent) {
		if (i.is_regular_file() && i.path().extension() == ".dll") {
			auto lib = LoadLibrary(i.path().c_str());
			if (lib) {
				do_log(L"loaded %s\n", canonical(i.path()).c_str());
			}
			else {
				do_log(L"Error when loading %s\n", i.path().c_str());
				PrintErrorMessage();
			}
		}
	}
}
void entry(){
	//sometest();
	XIDREG::initAll();
	loadall();
	PostInitEvent::_call();
	PostInitEvent::_removeall();
}
/*
THook(void, "?handle@ServerNetworkHandler@@UEAAXAEBVNetworkIdentifier@@AEBVItemFrameDropItemPacket@@@Z") {

}*/
