#pragma once
extern "C" {
	// The core api of the hook function
	__declspec(dllimport) int HookFunction(void* oldfunc, void** poutold, void* newfunc);
	// Used to get a server-defined specific function by name
	__declspec(dllimport) void* GetServerSymbol(char const* name);
}