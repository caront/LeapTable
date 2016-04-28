//controller.hpp

#ifndef __CONTROLLER_HPP__
#define __CONTROLLER_HPP__

#include <iostream>
#include "Page.hpp"
#include "CallBackListener.hpp"
#include "UIMenu.hpp"
#include "ScreenInfo.hpp"
#include "WindowXMlReader.hpp"

class WindowXMlReader;
class CollectionElement;
class Core;
class Page;


class Controller
{
public:
	Page	*page;
	UIMenu 	*menu;

private:
	Core	*_core;
	sf::RenderWindow *window;
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