#ifndef __UIMENU_H__
#define __UIMENU_H__ 

#include <cmath>
#include "UIMenuElement.hpp"
#include "Color.hh"

#define PI 3.14159265

class UIMenu
{
private:
	UIMenuElement *_up;
	UIMenuElement *_down;
	UIMenuElement *_left;
	UIMenuElement *_right;
	Color color;
	sf::CircleShape *shape;

public:
	UIMenu();
	~UIMenu();

	void Draw(sf::RenderWindow *window);
	void Init(sf::RenderWindow *window);

	void addElement(UIMenuElement *value);
	void setUpButton(UIMenuElement *value);
	void setDownButton(UIMenuElement *value);
	void setLeftButton(UIMenuElement *value);
	void setRightButton(UIMenuElement *value);

	UIObject *GetObjectOnFocus(sf::Event *event);
	UIObject *GetObjectOnClick(sf::Event *event);

	void setColor(int value);
};

#endif
