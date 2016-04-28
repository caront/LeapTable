#include "UIMenu.hpp"
#include "Log.hpp"


UIMenu::UIMenu()
{
	shape = new sf::CircleShape();
}

UIMenu::~UIMenu()
{

}

void UIMenu::Init(sf::RenderWindow *window)
{
	shape->setOrigin(150, 150);
	shape->setRadius(300);

	shape->setPosition(
			sf::Vector2f(static_cast<float>((window->getSize().x / 2) - 150),
			 			static_cast<float>((window->getSize().y /2) - 150)));
	shape->setFillColor(sf::Color(color.argb.r, color.argb.g, color.argb.b, 100));
	shape->setOutlineColor(sf::Color(color.argb.r, color.argb.g, color.argb.b, color.argb.a));
	shape->setOutlineThickness(3);
}

void UIMenu::addElement(UIMenuElement *value)
{
	if (value->getTag() == "Up")
		setUpButton(value);
	if (value->getTag() == "Down")
		setDownButton(value);
	if (value->getTag() == "Left")
		setLeftButton(value);
	if (value->getTag() == "Right")
		setRightButton(value);
}

void UIMenu::setUpButton(UIMenuElement *value)
{
	_up = value;
	_up->setPosX(45);
	_up->setPosY(15);
}

void UIMenu::setDownButton(UIMenuElement *value)
{
	_down = value;
	_down->setPosX(45);
	_down->setPosY(65);
}

void UIMenu::setLeftButton(UIMenuElement *value)
{
	_left = value;
	_left->setPosX(30);
	_left->setPosY(40);
}

void UIMenu::setRightButton(UIMenuElement *value)
{
	_right = value;
	_right->setPosX(60);
	_right->setPosY(40);
}

void UIMenu::Draw(sf::RenderWindow *window)
{
	window->draw(*shape);
	_right->Draw(window);
	_left->Draw(window);
	_up->Draw(window);
	_down->Draw(window);
	window->display();
}

UIObject *UIMenu::GetObjectOnFocus(sf::Event *event)
{
	if (_up->OnFocus(event))
		return _up;
	if (_down->OnFocus(event))
		return _down;
	if (_left->OnFocus(event))
		return _left;
	if (_right->OnFocus(event))
		return _right;
	return NULL;
}

UIObject *UIMenu::GetObjectOnClick(sf::Event *event)
{
	if (_up->OnClick(event))
		return _up;
	if (_down->OnClick(event))
		return _down;
	if (_left->OnClick(event))
		return _left;
	if (_right->OnClick(event))
		return _right;
	return NULL;
}

void UIMenu::setColor(int value)
{
	color.c = value;
	std::cout << value << std::endl;
	shape->setOutlineColor(sf::Color(color.argb.r, color.argb.g, color.argb.b, color.argb.a));
}