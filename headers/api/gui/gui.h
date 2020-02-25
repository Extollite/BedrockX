#pragma once
#include<pch.h>
#include<rapidjson/document.h>
#include<rapidjson/stringbuffer.h>
#include<variant>
#include<array>
using std::variant;
struct GUIButton {
	string name;
	string img;
	bool isUrl;
	GUIButton(string&& _name):name(_name),isUrl(false){}
	GUIButton(string&& _name, string&& _img,bool Url=true):name(_name),img(_img),isUrl(Url) {}
	LIGHTBASE_API void pack(rapidjson::Value&,rapidjson::Document::AllocatorType&) const;
};
struct GUIInput {
	string text, ph;
	GUIInput(string&& _text, string&& placeholder = ""):text(_text),ph(placeholder) {}
	LIGHTBASE_API void pack(rapidjson::Value&, rapidjson::Document::AllocatorType&) const;
};
struct GUIToggle {
	string text;
	bool state;
	GUIToggle(string&& _text, bool defualt=false) :text(_text), state(defualt) {}
	LIGHTBASE_API void pack(rapidjson::Value&, rapidjson::Document::AllocatorType&) const;
};
struct GUILabel {
	string text;
	GUILabel (string&& _text) : text(_text) {}
	LIGHTBASE_API void pack(rapidjson::Value&, rapidjson::Document::AllocatorType&) const;
};
struct GUISlider {
	string text;
	int min, max,step,def;
	GUISlider(string&& t,int _min,int _max,int _step=1,int _def=0):text(t),min(_min),max(_max),step(_step),def(_def){}
	LIGHTBASE_API void pack(rapidjson::Value&, rapidjson::Document::AllocatorType&) const;
};
struct GUIDropdown {
	std::vector<string> options;
	string text;
	int def;
	GUIDropdown(string&& t, std::vector<string>&& option,int _def=0):text(t),def(_def),options(option){}
	LIGHTBASE_API void pack(rapidjson::Value&, rapidjson::Document::AllocatorType&) const;
};
class IForm {
public:
	virtual ~IForm(){}
	virtual string_view seralize()=0;
};
using GUI_WIDGET_T = variant<GUIInput,GUIDropdown,GUISlider,GUILabel,GUIToggle>;
class FullForm:public IForm {
	string title;
	bool seralized;
	rapidjson::StringBuffer json;
public:
	std::vector<GUI_WIDGET_T> widgets;
	LIGHTBASE_API FullForm();
	LIGHTBASE_API void addWidget(GUI_WIDGET_T&& wd);
	LIGHTBASE_API string_view seralize();
		void reset() {
			widgets.clear();
			json.Clear();
			seralized = false;
		}
};
class SimpleForm :public IForm {
	string title;
	string content;
	bool seralized;
	rapidjson::StringBuffer json;
public:
	std::vector<GUIButton> buttons;
	LIGHTBASE_API SimpleForm();
	LIGHTBASE_API void addButton(GUIButton&& wd);
	LIGHTBASE_API string_view seralize();
	void reset() {
		buttons.clear();
		json.Clear();
		seralized = false;
	}
};
LIGHTBASE_API unsigned int newFormID();
class IFormBinder {
public:
	unsigned int formid;
	virtual ~IFormBinder() {}
	virtual void invoke(ServerPlayer& sp, string_view sv) = 0;
	virtual string_view seralize() = 0;
};
template<class T>
class FormBinder :public IFormBinder{
public:
	shared_ptr<T> form;
	function<void(ServerPlayer&, T&,string_view)> callback;
	FormBinder(shared_ptr<T> fm, function<void(ServerPlayer&, T&, string_view)>&& cb) :form(fm),callback(cb) {
		formid = newFormID();
	};
	virtual void invoke(ServerPlayer& sp, string_view sv) {
		callback(sp, *form, sv);
	}
	virtual string_view seralize() {
		return form->seralize();
	}
};
template<size_t sz>
static bool parseFormResult(string_view sv,std::array<variant<string,int>,sz>& args) {
	if (sv.size() == 0 || sv[0] == 'n') return false; //null
	rapidjson::Document dc;
	dc.Parse(sv);
	if (dc.HasParseError()) return false;
	if (!dc.IsArray()) return false;
	if (dc.GetArray().Size() != sz) return false;
	auto& arr = dc.GetArray();
	for (int i = 0; i < sz; ++i) {
		auto& tmp = arr[i];
		if (tmp.IsInt()) {
			args[i] = tmp.GetInt();
		}
		if (tmp.IsString()) {
			args[i] = tmp.GetString();
		}
		printf("type %d\n",tmp.GetType());
	}
	return true;
}
static bool parseFormResult(string_view sv, int& btn) {
	if (sv.size() == 0 || sv[0] == 'n') return false; //null
	btn = atoi(sv);
	return true;
}
LIGHTBASE_API void sendForm(ServerPlayer& sp, FormBinder<FullForm>&& form);
LIGHTBASE_API void sendForm(ServerPlayer& sp, FormBinder<SimpleForm>&& form);