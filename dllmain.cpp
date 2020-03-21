// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include<lbpch.h>
#include "framework.h"
#include<iostream>
void entry();
LBAPI void WaitForDebugger() {
	while (!IsDebuggerPresent())
		Sleep(200);
}
void HookFunction__begin();
long HookFunction__finalize();
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD ul_reason_for_call,
	LPVOID lpReserved) { 
	switch (ul_reason_for_call) { 
	case DLL_PROCESS_ATTACH: {
		DisableThreadLibraryCalls(hModule);
		system("chcp 65001");
		std::ios::sync_with_stdio(false);
		entry();
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
