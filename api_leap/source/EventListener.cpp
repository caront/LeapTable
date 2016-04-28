#include "EventListener.hpp"
#include "Log.hpp"

EventListener::EventListener(){
	menushow = false;
}

EventListener::~EventListener(){}

void EventListener::Init()
{
	_prosse = new Prosse();
	_prosse->Init();
	_prosse->Open();
}

void EventListener::setCloseEvent(std::function<void(void*, void*)> event)
{
	_closeCallBack = event;
}

void EventListener::setShowMenuEvent(std::function<void(void*, void*)> event){
	_showMenuCallBack = event;
}

void EventListener::setHideMenuEvent(std::function<void(void*, void*)> event){
	_hideMenuCallBack = event;
}

void EventListener::setStartEvent(std::function<void(void*, void*)> event){
	_startCallBack = event;
}

void EventListener::execCloseEvent(void* arg1, void* arg2){
	_closeCallBack(arg1, arg2);
}

void EventListener::execShowMenuEvent(void* arg1, void* arg2){
	_showMenuCallBack(arg1, arg2);
}

void EventListener::execHideMenuEvent(void* arg1, void* arg2){
	_hideMenuCallBack(arg1, arg2);
}

void EventListener::execStartEvent(void* arg1, void* arg2){
	_startCallBack(arg1, arg2);
}

void EventListener::CheckEvent(void* arg1, void *arg2){
	if (_prosse->GetData() == STOP)
		execCloseEvent(arg1, arg2);
	else if (_prosse->GetData() == SHOWMENU)
	{
		if (!menushow)
			execShowMenuEvent(arg1, arg2);
		else
			execHideMenuEvent(arg1, arg2);
		menushow = !menushow;
	}
	_prosse->PutData("");
}