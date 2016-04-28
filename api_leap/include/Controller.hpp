//controller.hpp

#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <iostream>
#include "Page.hpp"
#include "CallBackListener.hpp"
#include "UIMenu.hpp"
#include "ScreenInfo.hpp"
#include "WindowXMlReader.hpp"
#include "OpenGlUtils.hpp"
#include "Object3D.hpp"

class WindowXMlReader;
class CollectionElement;
class Core;
class Page;


class Controller
{
public:
	Page	*page;
	UIMenu 	*menu;
	Object3D *object3D;
private:
	Core	*_core;
	sf::RenderWindow *window;
	OpenGlUtils 	*openGlUtils;
	WindowXMlReader	 *reader;
	sf::RectangleShape *menushadow;
	
public:
	Controller(Core *core);
	~Controller();

	void Init(UIMenu *menu);

	void LoadPage(Page *page);
	void Render(bool showMenu);
	void Event(bool menuEvent);

	bool IsWindowOpen();
	void ShowMenu();

private:
	void EventPage();
	void EventMenu();
};

#endif