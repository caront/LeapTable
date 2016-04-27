#ifndef __UIOBJECT_LIST_H__
#define __UIOBJECT_LIST_H__


#include <SFML/Window.hpp>
#include <map>

#include "UIObject.hpp"

typedef std::map<std::string, UIObject*>::iterator UIObjectIterator;

class UIObjectList
{
private:
	std::map<std::string, UIObject *> _objectList;

public:
	UIObjectList();
	~UIObjectList();

	void Add(UIObject *newObject);
	void Draw(sf::RenderWindow *windows);
	void OnWindowsSizeChange(float x, float y);

	UIObject *GetObjectOnFocus(sf::Event *event);
	UIObject *GetObjectOnClick(sf::Event *event);

	UIObject *GetObjectByTag(std::string tag);
	
};

#endif