#include <pch.h>
template <class T>
LIGHTBASE_API T* LocateS<T>::_srv;
THook(void, "?setup@ChangeSettingCommand@@SAXAEAVCommandRegistry@@@Z", CommandRegistry* rg, void* a1) {
	LocateS<CommandRegistry>::assign(*rg);
	original(rg, a1);
	RegisterCommandEvent::_call();
	RegisterCommandEvent::_removeall();
}
