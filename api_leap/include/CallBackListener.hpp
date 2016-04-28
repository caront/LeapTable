//CallBackListener.hpp

#ifndef __CALLBACKLISTENER_H__
#define __CALLBACKLISTENER_H__

#include <map>
#include <functional>
#include <string>

class CallBackListener
{
private:
	std::map < std::string, std::function<void(void*, void*)>> _listener;

public:
	CallBackListener();
	~CallBackListener();

	void Add(std::string, std::function<void(void*, void*)>);

	std::function<void(void*, void*)> GetFunctionByTag(std::string);
};

#endif