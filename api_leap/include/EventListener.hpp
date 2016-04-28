#ifndef __EVENT_LISTENER_H__
#define __EVENT_LISTENER_H__

#include <map>
#include <functional>
#include <string>

#include "Prosse.hpp"

class EventListener
{
private:
	std::function<void(void*, void*)> _closeCallBack;
	std::function<void(void*, void*)> _showMenuCallBack;
	std::function<void(void*, void*)> _hideMenuCallBack;
	std::function<void(void*, void*)> _startCallBack;
	Prosse *_prosse;

public:
	bool menushow;

	
public:
	EventListener();
	~EventListener();
	
	void Init();
	void setCloseEvent(std::function<void(void*, void*)> event);
	void setShowMenuEvent(std::function<void(void*, void*)> event);
	void setHideMenuEvent(std::function<void(void*, void*)> event);
	void setStartEvent(std::function<void(void*, void*)> event);

	void execCloseEvent(void*, void*);
	void execShowMenuEvent(void*, void*);
	void execHideMenuEvent(void*, void*);
	void execStartEvent(void*, void*);

	void CheckEvent(void* arg1, void *arg2);
};

#endif