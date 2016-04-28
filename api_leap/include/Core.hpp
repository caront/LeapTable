#ifndef __CORE_H__
#define __CORE_H__

#include "UIWindow.hpp"
#include "UIButton.hpp"
#include "Controller.hpp"
#include "OpenGlUtils.hpp"
#include "EventListener.hpp"

#include "Object3D.hpp"

class Controller;
class CollectionElement;

class Core
{
public:
	CollectionElement *collectionElement;
	EventListener 	*event;

private:
	Controller *controller;


public :
	Core(std::string folderpath, CallBackListener *callBackListener);
	~Core();

	void Init();
	void Run();
	void Finish();


	void NavigateTo(std::string pageTag);
};

#endif