//controller.hpp

#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <iostream>
#include "Page.hpp"
#include "CallBackListener.hpp"

#include "ScreenInfo.hpp"
#include "WindowXMlReader.hpp"

class WindowXMlReader;
class CollectionElement;
class Core;
class Page;


class Controller
{
private:
	Page	*page;
	Core	*_core;
	sf::RenderWindow *window;
	WindowXMlReader	 *reader;
	
public:
	Controller(Core *core);
	~Controller();

	void Init();

	void LoadPage(Page *page);
	void Render();
	void Event();

	bool IsWindowOpen();
	
};

#endif