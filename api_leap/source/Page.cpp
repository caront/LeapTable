//page.cpp

#include "Page.hpp"


Page::Page()
{
	_listObject = new UIObjectList();
	background = new sf::RectangleShape();
}

Page::~Page()
{

}

void Page::Init(float x, float y)
{
	background->setSize(sf::Vector2f(x, y));
	_listObject->OnWindowsSizeChange(x, y);
}

void Page::AddElement(UIObject *obj)
{
	_listObject->Add(obj);
}

void Page::OnWindowSizeChange(float x, float y)
{
	background->setSize(sf::Vector2f(x, y));
	_listObject->OnWindowsSizeChange(x, y);
}

void Page::Draw(sf::RenderWindow *window)
{
	window->draw(*background);
	_listObject->Draw(window);
}

std::string Page::getTag() const
{
	return _tag;
}

UIObject *Page::GetObjectOnFocus(sf::Event *event)
{
	return _listObject->GetObjectOnFocus(event);
}

UIObject *Page::GetObjectOnClick(sf::Event *event)
{
	return _listObject->GetObjectOnClick(event);
}

UIObjectList	*Page::GetObjectList(){
	return _listObject;
}
void Page::SetObjectList(UIObjectList *obj){
	_listObject = obj;
}

void		Page::setTag(std::string value)
{
	_tag = value;
}
void		Page::setBackground(int value)
{
	_background.c = value;
	background->setFillColor(sf::Color(_background.argb.r, _background.argb.g, _background.argb.b, _background.argb.a));

}
