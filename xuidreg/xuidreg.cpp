#include<lbpch.h>
#include<stl\KVDB.h>
#include<stl\viewhelper.h>
#include<api\event\playerEvent.h>
#include<api\xuidreg\xuidreg.h>
#include<mcapi/Certificate.h>
namespace XIDREG {
	static KVDBImpl xuiddb("xuiddb");
	/*	LBAPI optional<string> id2str(xuid_t xid);
	LBAPI optional<xuid_t> str2id(string const& name);
	LBAPI void foreach (std::function<bool(xuid_t, string_view)>&&);*/
	LBAPI optional<xuid_t> str2id(string_view _name) {
		if (_name.size() >= 512)
			return {};
		if (_name == "system")
			return { 0 };
		char buf[512];
		for (int i = 0; i < _name.size(); ++i) {
			buf[i] = std::tolower(_name[i]);
		}
		string_view name(buf, _name.size());
		string rv;
		if (xuiddb.get(name, rv) && rv.size() == 8) {
			return { *(xuid_t*)(rv.data()) };
		}
		return {};
	}
	LBAPI optional<string> id2str(xuid_t id) {
		if (id == 0) {
			return { "system" };
		}
		string val;
		if (xuiddb.get(to_view(id), val))
			return { val };
		return {};
	}
	LBAPI void foreach(std::function<bool(xuid_t, string_view)>&&x) {
		xuiddb.iter([&](string_view k, string_view v) -> bool {
			if (k.size() == 8 && v.size() != 8) {
				return x(*(xuid_t*)k.data(), v);
			}
			return true;
		});
	}
	static void insert(xuid_t id, string_view _name) {
		if (_name.size() >= 512)
			return;
		char buf[512];
		for (int i = 0; i < _name.size(); ++i) {
			buf[i] = std::tolower(_name[i]);
		}
		string_view name(buf, _name.size());
		string val;
		if (xuiddb.get(name, val)) {
			if (val != to_view(id)) {
				LOG("[BASE/XUID] update", _name, "'s xuid->", id);
				xuiddb.del(val);
				xuiddb.put(name, to_view(id));
				xuiddb.put(to_view(id), name);
			}
		}
		else {
			LOG("[BASE/XUID] insert", _name, "'s xuid", id);
			xuiddb.put(name, to_view(id));
			xuiddb.put(to_view(id), name);
		}
	}
	void initAll() {
		addListener([](PlayerPreJoinEvent& ev) {
			auto& cert = ev.cert;
			auto name = ExtendedCertificate::getIdentityName(cert);
			auto _xuid = ExtendedCertificate::getXuid(cert);
			xuid_t xuid;
			if (_xuid.size() <= 1)
				xuid = 114514;
			else
				xuid = std::stoull(_xuid);
			insert(xuid, name);
		});
	}
};