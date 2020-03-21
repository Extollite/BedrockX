#include <lbpch.h>
#include<api\event\genericEvent.h>
#include<api\serviceLocate.h>
class CommandRegistry;
template <class T>
LIGHTBASE_API T* LocateS<T>::_srv;
THook(void, "?setup@ChangeSettingCommand@@SAXAEAVCommandRegistry@@@Z", CommandRegistry* rg, void* a1) {
	LocateS<CommandRegistry>::assign(*rg);
	original(rg, a1);
	RegisterCommandEvent::_call();
	RegisterCommandEvent::_removeall();
}
