#pragma once
#include<string>
#include<mcapi/Core.h>
using std::string;
namespace XIDREG {
	LBAPI bool id2str(xuid_t xid,string& val);
	LBAPI bool str2id(string const& name,xuid_t& val);
	void initAll();
}