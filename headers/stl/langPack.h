#pragma once
#include<unordered_map>
#include<api/hash.h>
#include<string>
namespace LangPack {
	using std::string;
	static std::unordered_map<CHash, string> TMAP;
#if 0	
static void load(const string& path) {
		config = YAML::LoadFile(path);
		for (const auto& i : config) {
			TMAP[hash(i.first.as<string>())] = i.second.as<string>();
		}
	}
#endif
	static void load2(std::unordered_map<string,string>& mp){
		for(auto& i:mp) TMAP.emplace(do_hash(i.first.data(),i.first.size()),i.second);
	}
	template<CHash HASH>
	static const string& trans() {
		static string* cache = NULL;
		if (cache == NULL) cache = &TMAP[HASH];
		return *cache;
	}
};
#define _TRS(x) (LangPack::trans<do_hash((x))>())
#define _TR(x) (LangPack::trans<do_hash((x))>().c_str())