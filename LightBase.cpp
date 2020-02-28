// LightBase.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include <api/gui/gui.h>
#include <filesystem>
#include "framework.h"

void sometest() {
	addListener(
		[](PlayerJoinEvent& ev) {
			printf("barrier\n");
			printf("listen %s %d\n",ev.getPlayer().getName().c_str(), ev.getPlayer()->getCarriedItem().getId());
			auto sp = ev.getPlayer();
			LocateS<MainHandler>()->schedule(DelayedTask([sp]() {
				printf("add %d\n", sp.v->getCarriedItem().getId());
			},
				2,true));
			return;
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
static void loadall() {
	do_log(L"BedrockX Loaded!\n");
	addListener(function([](ServerStartedEvent& ev) {
		printf("server started\n");
		LocateS<MainHandler>()->schedule(DelayedTask([]() {
			LocateS<WLevel>()->getUsers();
		},
			2, false));
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
				printf("last error %ul\n", GetLastError());
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
