#ifndef  PCH_H
#define PCH_H
#include<cstdio>
#include<cstring>
#include<string>
#include<string_view>
#include<functional>
#include<memory>
#include<vector>
#include<unordered_map>
#include<list>
#include<type_traits>
using std::string, std::string_view,std::shared_ptr,std::unique_ptr,std::vector,std::unordered_map,
std::ifstream,std::ofstream,std::function;
#define do_log wprintf
#define do_dbg_log wprintf
#include"api/hash.h"
#include"api/lightbase.h"
#include"api/hook.h"
#include"api/Loader.h"
#include<mcapi/Core.h>
#include<api/serviceLocate.h>
#include<stl/views.h>
/*
#ifdef JSON_SUPPORT
#include<rapidjson/document.h>
#include<rapidjson/error/en.h>
#ifdef JSON_WRTIE
#include<rapidjson/writer.h>
#include<rapidjson/stringbuffer.h>
#endif
#endif*/
#endif