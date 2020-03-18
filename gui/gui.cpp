#include<lbpch.h>
#include <api/gui/gui.h>
#include <rapidjson/writer.h>
#include<api\refl\playerMap.h>
#include<stl\varint.h>
#include<api\myPacket.h>
#include<mcapi/Player.h>
namespace GUI {
	using rapidjson::Value;
	LIGHTBASE_API unsigned int newFormID() {
		static int fid;
		return ++fid;
	}
	static playerMap<std::unique_ptr<IFormBinder>> formMap;
	LIGHTBASE_API void sendForm(ServerPlayer& sp, FormBinder<FullForm>&& form) {
		auto payload = form.seralize();
		WBStream ws;
		ws.apply(VarUInt(form.formid), MCString(payload));
		MyPkt<100, false> guipk{ ws.data };
		sp.sendNetworkPacket(guipk);
		formMap._map.emplace(&sp, std::make_unique<FormBinder<FullForm>>(std::forward<FormBinder<FullForm>>(form)));
	}

	LIGHTBASE_API void sendForm(ServerPlayer& sp, FormBinder<SimpleForm>&& form) {
		auto payload = form.seralize();
		WBStream ws;
		ws.apply(VarUInt(form.formid), MCString(payload));
		MyPkt<100, false> guipk{ std::move(ws.data) };
		sp.sendNetworkPacket(guipk);
		formMap._map.emplace(&sp, std::make_unique<FormBinder<SimpleForm>>(std::forward<FormBinder<SimpleForm>>(form)));
	}
#define strval(x) Value(x.data(), (rapidjson::SizeType)x.size())
#define addmem(k, val) v.AddMember(#k, val, ac)
	LIGHTBASE_API void GUIButton::pack(rapidjson::Value& v, rapidjson::Document::AllocatorType& ac) const {
		v.SetObject();
		addmem(text, strval(this->name));
		if (img.size() != 0) {
			Value tmp;
			tmp.SetObject();
			tmp.AddMember("type", isUrl ? Value("url", 3) : Value("path", 4), ac);
			tmp.AddMember("data", strval(img), ac);
			v.AddMember("image", std::move(tmp), ac);
		}
	}

	LIGHTBASE_API void GUIInput::pack(rapidjson::Value& v, rapidjson::Document::AllocatorType& ac) const {
		v.SetObject();
		addmem(type, "input");
		addmem(text, strval(text));
		addmem(placeholder, strval(ph));
		addmem(default, "");
	}
	LIGHTBASE_API void GUILabel::pack(rapidjson::Value& v, rapidjson::Document::AllocatorType& ac) const {
		v.SetObject();
		addmem(type, "label");
		addmem(text, strval(text));
	}
	LIGHTBASE_API void GUIToggle::pack(rapidjson::Value& v, rapidjson::Document::AllocatorType& ac) const {
		v.SetObject();
		addmem(type, "toggle");
		addmem(text, strval(text));
		addmem(default, this->state);
	}
	LIGHTBASE_API void GUISlider::pack(rapidjson::Value& v, rapidjson::Document::AllocatorType& ac) const {
		v.SetObject();
		addmem(type, "slider");
		addmem(text, strval(text));
		addmem(default, this->def);
		addmem(min, this->min);
		addmem(max, this->max);
		addmem(step, this->step);
	}
	LIGHTBASE_API void GUIDropdown::pack(rapidjson::Value& v, rapidjson::Document::AllocatorType& ac) const {
		v.SetObject();
		addmem(type, "dropdown");
		addmem(text, strval(text));
		addmem(default, this->def);
		Value tmp;
		tmp.SetArray();
		for (auto& i : this->options) {
			tmp.PushBack(strval(i), ac);
		}
		addmem(options, std::move(tmp));
	}
	LIGHTBASE_API SimpleForm::SimpleForm() {
		seralized = false;
	}
	LIGHTBASE_API void SimpleForm::addButton(GUIButton&& wd) {
		buttons.emplace_back(wd);
	}
	LIGHTBASE_API string_view SimpleForm::seralize() {
		if (seralized)
			return { json.GetString(), json.GetSize() };
		using namespace rapidjson;
		Document dc;
		dc.SetObject();
		auto& ac = dc.GetAllocator();
		dc.AddMember("type", "form", ac);
		dc.AddMember("title", strval(title), ac);
		dc.AddMember("content", strval(content), ac);
		Value btn;
		btn.SetArray();
		for (auto& i : buttons) {
			Value tmp;
			i.pack(tmp, ac);
			btn.PushBack(std::move(tmp), dc.GetAllocator());
		}
		dc.AddMember("buttons", std::move(btn), dc.GetAllocator());
		Writer<StringBuffer> writer(json);
		dc.Accept(writer);
		seralized = true;
		json.ShrinkToFit();
		return { json.GetString(), json.GetSize() };
	}
	LIGHTBASE_API FullForm::FullForm() {
		seralized = false;
	}
	LIGHTBASE_API void FullForm::addWidget(GUI_WIDGET_T&& wd) {
		widgets.emplace_back(wd);
	}
	LIGHTBASE_API string_view FullForm::seralize() {
		if (seralized)
			return { json.GetString(), json.GetSize() };
		using namespace rapidjson;
		Document dc;
		dc.SetObject();
		auto& ac = dc.GetAllocator();
		dc.AddMember("type", "custom_form", ac);
		dc.AddMember("title", strval(title), ac);
		Value v;
		v.SetArray();
		for (auto& i : widgets) {
			Value tmp;
			std::visit([&](auto& widget) -> void {
				widget.pack(tmp, ac);
			},
				i);
			v.PushBack(std::move(tmp), ac);
		}
		dc.AddMember("content", std::move(v), ac);
		Writer<StringBuffer> writer(json);
		dc.Accept(writer);
		seralized = true;
		json.ShrinkToFit();
		return { json.GetString(), json.GetSize() };
	}
};
THook(void, "?handle@?$PacketHandlerDispatcherInstance@VModalFormResponsePacket@@$0A@@@UEBAXAEBVNetworkIdentifier@@AEAVNetEventCallback@@AEAV?$shared_ptr@VPacket@@@std@@@Z", void* fake, NetworkIdentifier const& neti, ServerNetworkHandler& snh, unsigned char** pk) {
	using namespace GUI;
	original(fake, neti, snh, pk);
	unsigned char* pkt = *pk;
	ServerPlayer* sp = snh._getServerPlayer(neti, pkt[16]);
	if (sp) {
		auto it = formMap._map.find(sp);
		if (it != formMap._map.end()) {
			auto& fid = *(unsigned int*)(pkt + 40);
			auto& str = *(string*)(pkt + 48);
			if (it->second->formid != fid)
				return;
			std::unique_ptr<IFormBinder> pBinder;
			pBinder.swap(it->second);
			formMap._map.erase(it);
			pBinder->invoke(*sp, str);
		}
	}
}