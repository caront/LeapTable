//CallBackListener.cpp

#include "CallBackListener.hpp"
#include "CallBack.hpp"

CallBackListener::CallBackListener()
{

}


CallBackListener::~CallBackListener()
{
}

void CallBackListener::Init()
{
	Add("Test", OnClickTest);
	Add("OnButtonClick_1", OnButtonClick_1);
	Add("OnButtonClick_2", OnButtonClick_2);
	Add("OnButtonClick_3", OnButtonClick_3);
	Add("OnButtonClick_4", OnButtonClick_4);
}

void CallBackListener::Add(std::string tag, std::function<void(void*, void*)> function)
{
	_listener[tag] = function;
}

std::function<void(void*, void*)> CallBackListener::GetFunctionByTag(std::string tag)
{
	return _listener[tag];
}