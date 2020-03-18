#pragma once
#include"lightbase.h"
extern "C" {
// The core api of the hook function
	__declspec(dllimport) int HookFunction(void* oldfunc, void** poutold, void* newfunc);
// Used to get a server-defined specific function by name
	LBAPI void* dlsym_real(char const* name);
	LBAPI void WaitForDebugger();
}