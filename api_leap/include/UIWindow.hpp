#ifndef __UIWINDOW_H_
#define __UIWINDOW_H_


#include <SFML/Window.hpp>
#include <list>

#include "UIObject.hpp"

class UIWindow : public sf::RenderWindow
{
private:
	std::list<UIObject *> _objectList;


public:
	UIWindow(std::string windowName, int h, int w);
	~UIWindow();

	void Init();
	void Add(UIObject *newObject);
	void Refresh();

	bool IsOpen();

private:
	void Clean();
	void Draw();

};

#endif