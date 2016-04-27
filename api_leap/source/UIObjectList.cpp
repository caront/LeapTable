#include "UIObjectList.hpp"


UIObjectList::UIObjectList()
{
}


UIObjectList::~UIObjectList()
{
}


void UIObjectList::Add(UIObject *newObject)
{
	_objectList[newObject->getTag()] = newObject;
}

void UIObjectList::Draw(sf::RenderWindow *windows)
{
	for (UIObjectIterator it = _objectList.begin(); it != _objectList.end(); it++)
	{
		(*it).second->Reset();
		(*it).second->Draw(windows);
	}

}

void	UIObjectList::OnWindowsSizeChange(float x, float y)
{
	for (UIObjectIterator it = _objectList.begin(); it != _objectList.end(); it++)
	{
		(*it).second->OnWindowsSizeChange(x, y);
	}
}

UIObject *UIObjectList::GetObjectOnFocus(sf::Event *event)
{
	for (UIObjectIterator it = _objectList.begin(); it != _objectList.end(); it++)
	{
		
		if ((*it).second->OnFocus(event))
			return (*it).second;
	}
	return NULL;
}


UIObject *UIObjectList::GetObjectOnClick(sf::Event *event)
{
	for (UIObjectIterator it = _objectList.begin(); it != _objectList.end(); it++)
	{
		if ((*it).second->OnClick(event))
			return (*it).second;
	}
	return NULL;
}

UIObject *UIObjectList::GetObjectByTag(std::string tag)
{
	for (UIObjectIterator it = _objectList.begin(); it != _objectList.end(); it++)
	{
		if ((*it).second->getTag() == tag)
			return (*it).second;
	}
	return NULL;
}
