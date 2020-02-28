#pragma once
#include"types.h"
#include<string>
namespace BDX {
	using std::string;
	LBAPI bool runcmd(const string& cmd);
	LBAPI bool runcmdAs(WPlayer, const string& cmd);
};