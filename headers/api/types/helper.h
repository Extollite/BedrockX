#pragma once
struct WPlayer;
#include<string>
namespace BDX {
	using std::string;
	LBAPI bool runcmd(const string& cmd);
	LBAPI bool runcmdAs(WPlayer, const string& cmd);
	LBAPI string getIP(class NetworkIdentifier&);
};