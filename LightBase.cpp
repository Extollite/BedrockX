// LightBase.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include<api/gui/gui.h>
#include<filesystem>
#include"framework.h"

void sometest() {
	addListener(
		[](PlayerJoinEvent& ev) {
			printf("listen\n");
			auto sf = std::make_shared <FullForm>();
			sf->addWidget(GUIDropdown("114514", { "kksk","1919810" }, 1));
			sf->addWidget(GUIInput("wtfwtf", "1919810"));
			sf->addWidget(GUISlider("sss", 1, 100));
			sf->addWidget(GUIToggle("xxx"));
			sf->addWidget(GUILabel("label"));
			sendForm(ev.getPlayer(), FormBinder(sf, function([](ServerPlayer& sp, FullForm& sf, string_view x) {
				std::cout << x << std::endl;
				})));
		});
}
static void loadall() {
	do_log(L"BedrockX Loaded!\n");
	addListener(function([](ServerStartedEvent& ev) {
		printf("server started\n");
		}));
	using namespace std::filesystem;
	create_directory("bdxmod");
	directory_iterator ent("bdxmod");
	for (auto& i : ent) {
		if (i.is_regular_file() && i.path().extension() == ".dll") {
			auto lib = LoadLibrary(i.path().c_str());
			if (lib) {
				do_log(L"loaded %s\n", canonical(i.path()).c_str());
			}
			else {
				do_log(L"Error when loading %s\n", i.path().c_str());
				printf("last error %d\n", GetLastError());
			}
		}
	}
}
THook(int, "main", int a, void* b) {
    sometest();
	loadall();
	PostInitEvent::_call();
	PostInitEvent::_removeall();
    printf("here\n");
	return original(a, b);
}
