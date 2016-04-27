#ifndef __CORE_H__
#define __CORE_H__

#include "UIWindow.hpp"
#include "UIButton.hpp"
#include "Controller.hpp"

class Controller;
class CollectionElement;

class Core
{
public:
	CollectionElement *collectionElement;

	

private:
	Controller *controller;


public :
	Core(std::string folderpath);
	~Core();

	void Init();
	void Run();
	void Finish();


	void NavigateTo(std::string pageTag);
};

#endif