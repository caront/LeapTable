//CallBackListener.cpp

#include "CallBackListener.hpp"


CallBackListener::CallBackListener()
{

}


CallBackListener::~CallBackListener()
{
}


void CallBackListener::Add(std::string tag, std::function<void(void*, void*)> function)
{
	_listener[tag] = function;
}

std::function<void(void*, void*)> CallBackListener::GetFunctionByTag(std::string tag)
{
	return _listener[tag];
}