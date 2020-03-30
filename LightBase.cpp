// LightBase.cpp : 定义 DLL 的导出函数。
//

#include<lbpch.h>
#include<iostream>
#include <filesystem>
#include "framework.h"
#include<api/xuidreg/xuidreg.h>
#include<api/event/genericEvent.h>
Logger<stdio_commit> LOG(stdio_commit{ "[BDX] " });
static void PrintErrorMessage() {
	DWORD errorMessageID = ::GetLastError();
	if (errorMessageID == 0) {
		std::wcerr << "wtf\n";
		return;
	}
	std::cerr << errorMessageID << std::endl;
	LPWSTR messageBuffer = nullptr;
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_SYSTEM , NULL, errorMessageID,
		MAKELANGID(0x09, SUBLANG_DEFAULT), (LPWSTR)&messageBuffer, 0, NULL);
	std::wcerr << messageBuffer << std::endl;
	LocalFree(messageBuffer);
}

static void fixupLIBDIR() {
	WCHAR* buffer=new WCHAR[8192];
	auto sz = GetEnvironmentVariableW(TEXT("PATH"), buffer, 8192);
	std::wstring PATH{ buffer, sz };
	sz = GetCurrentDirectoryW(8192, buffer);
	std::wstring CWD{ buffer, sz };
	SetEnvironmentVariableW(TEXT("PATH"), (CWD + L"\\bdxmod;" + PATH).c_str());
	delete[] buffer;
}
static void loadall() {
	static std::vector<std::pair<std::wstring, HMODULE>> libs;
	using namespace std::filesystem;
	create_directory("bdxmod");
	LOG("BedrockX Loaded!");
	fixupLIBDIR();
	directory_iterator ent("bdxmod");
	for (auto& i : ent) {
		if (i.is_regular_file() && i.path().extension() == ".dll") {
			auto lib = LoadLibrary(i.path().c_str());
			if (lib) {
				LOG("loaded", canonical(i.path()));
				libs.push_back({ std::wstring{ i.path().c_str() }, lib });
			}
			else {
				LOG.p<LOGLVL::Error>("Error when loading", i.path());
				PrintErrorMessage();
			}
		}
	}
	for (auto& [name, h] : libs) {
		auto FN = GetProcAddress(h, "onPostInit");
		if (!FN) {
			std::wcerr << "Warning!!! mod" << name << " doesnt have a onPostInit\n";
		}
		else {
			((void (*)()) FN)();
		}
	}
	libs.clear();
}
namespace GUI {
	void INIT();
};
void entry() {
	XIDREG::initAll();
	GUI::INIT();
	loadall();
	PostInitEvent::_call();
	PostInitEvent::_removeall();
}
THook(int, "main", void* a, void* b) {
	std::ios::sync_with_stdio(false);
	system("chcp 65001");
	entry();
	return original(a, b);
}