#pragma once
#include<iostream>
#include<fstream>
#include<streambuf>
#include<variant>
#include<string>
using std::variant,std::string;
static inline string ifs2str(std::ifstream& ifs) {
	return {(std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>()};
}