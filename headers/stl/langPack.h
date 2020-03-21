#pragma once
#include<unordered_map>
#include<api/hash.h>
#include<string>
#include<iostream>
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
static const string EMPTY;
	static void load2(std::unordered_map<string,string>& mp){
		for(auto& i:mp) TMAP.emplace(do_hash(i.first),i.second);
	}
	template<CHash HASH>
	static const string& trans(string_view x) {
		static string* cache = NULL;
		if (cache == NULL) {
			auto it = TMAP.find(HASH);
			if (it == TMAP.end()) {
				std::cerr << "[Error] Cannot find trans for " << x << "!!!\n";
				return EMPTY;
			}
			cache = &TMAP[HASH];
		}
		return *cache;
	}
};
#define _TRS(x) (LangPack::trans<do_hash((x))>(x))
#define _TR(x) (LangPack::trans<do_hash((x))>(x).c_str())