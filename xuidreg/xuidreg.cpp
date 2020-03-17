#include <pch.h>
namespace XIDREG {
	static KVDBImpl xuiddb("xuiddb");
	LBAPI bool str2id(string const& str, xuid_t& val) {
		string rv;
		if (xuiddb.get(str, rv) && rv.size() == 8) {
			val = *(xuid_t*)(rv.data());
			return true;
		}
		return false;
	}
	LBAPI bool id2str(xuid_t id, string& val) {
		if (id == 0) {
			val = "system";
			return true;
		}
		return xuiddb.get(to_view(id), val);
	}
	static void insert(xuid_t id, string const& name) {
		string val;
		if (xuiddb.get(name, val)) {
			if (val != to_view(id)) {
				printf("[BASE/XUID] update %s's xuid -> %I64u\n", name.c_str(), id);
				xuiddb.del(val);
				xuiddb.put(name, to_view(id));
				xuiddb.put(to_view(id), name);
			}
		}
		else {
			printf("[BASE/XUID]  insert %s's xuid %I64u\n", name.c_str(), id);
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