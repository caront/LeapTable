#include "UIWindow.hpp"


UIWindow::UIWindow(std::string windowName, int h, int w)
	: sf::RenderWindow(sf::VideoMode(800, 600), windowName, sf::Style::Fullscreen)
{
}


UIWindow::~UIWindow()
{
}

void UIWindow::Init()
{

}

void UIWindow::Add(UIObject *newObject)
{
	_objectList.push_back(newObject);
}

void UIWindow::Refresh()
{
	this->Clean();
	this->Draw();
}

void UIWindow::Draw()
{
	for (UIObject *obj : _objectList)
	{
		obj->Draw(this);
	}
	this->display();
}

void UIWindow::Clean()
{

}






