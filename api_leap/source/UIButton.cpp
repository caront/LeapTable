#include "UIButton.hpp"
#include "Log.hpp"

UIButton::UIButton(std::string Tag, float PosX, float PosY, float Height, float Width,
	int background, int foreground, int border, std::string Text, std::function<void(void*, void*)> onClickCallBack)
	: UIButton(Tag, PosX, PosY, Height, Width, background, foreground, border, Text)

{
	_onClickCallBack = onClickCallBack;
}

UIButton::UIButton(std::string Tag, float PosX, float PosY, float Height, float Width,
	int background, int foreground, int border, std::string Text)
	: UIObject(Tag, PosX, PosY, Height, Width)

{
	_background.c = background;
	_foreground.c = foreground;
	_border.c = border;
	_text = Text;
	this->InitiazeCompoment();
}


UIButton::UIButton(std::string Tag, float PosX, float PosY, float Height, float Width)
	: UIObject(Tag, PosX, PosY, Height, Width)
{
	this->InitiazeCompoment();
}


UIButton::~UIButton()
{
}

void		UIButton::InitiazeCompoment()
{
	sf::Font *font = new sf::Font();
	const std::string fontpath = "./window/Assets/Fonts/Aaargh.ttf";
	if (!font->loadFromFile(fontpath))
	{
		getchar();
	}
	shape = new sf::RectangleShape();
	shape->setSize(sf::Vector2f((float) _height, (float) _width));
	shape->setPosition(sf::Vector2f((float) _posX, (float) _posY));
	shape->setOutlineThickness(3);
	content = new UIText("", _posX, _posY, _text, font, 30, _foreground.c);
	content->originInMidle();
	this->Reset();
}

void		UIButton::Draw(sf::RenderWindow *window){
	if (_UIPropChanged)
		OnWindowsSizeChange(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y));
	window->draw(*shape);
	content->Draw(window);
	_UIPropChanged = false;
}



void		UIButton::Reset(){
	if (_isFocus)
	{
		shape->setOutlineColor(sf::Color(_background.argb.r, _background.argb.g, _background.argb.b, _background.argb.a));
		shape->setFillColor(sf::Color(_foreground.argb.r, _foreground.argb.g, _foreground.argb.b, _foreground.argb.a));
		if (_isClick)
		{
			shape->setOutlineColor(sf::Color(_background.argb.r, _background.argb.g, _background.argb.b, _background.argb.a));
			shape->setFillColor(sf::Color(_border.argb.r, _border.argb.g, _border.argb.b, _border.argb.a));
			content->setForground(_background);
			return;
		}
	}
	else
	{
		shape->setFillColor(sf::Color(_background.argb.r, _background.argb.g, _background.argb.b, _background.argb.a));
		shape->setOutlineColor(sf::Color(_foreground.argb.r, _foreground.argb.g, _foreground.argb.b, _foreground.argb.a));
		content->setForground(_foreground);

	}
}

bool		UIButton::OnClick(sf::Event *event){
	_isClick = false;
	if (event->mouseButton.x > shape->getPosition().x &&
		event->mouseButton.x <  shape->getPosition().x + shape->getSize().x)
	{
		if (event->mouseButton.y > shape->getPosition().y &&
			event->mouseButton.y <  shape->getPosition().y + shape->getSize().y)
			_isClick = true;
	}
	return _isClick;
}

bool		UIButton::OnFocus(sf::Event *event){
	_isFocus = false;
	if (event->mouseMove.x > shape->getPosition().x &&
		event->mouseMove.x <  shape->getPosition().x + shape->getSize().x)
	{
		if (event->mouseMove.y > shape->getPosition().y &&
			event->mouseMove.y < shape->getPosition().y + shape->getSize().y)
			_isFocus = true;
	}
	return _isFocus;
}


void		UIButton::OnFocus(sf::RenderWindow *window){
}

void		UIButton::OnWindowsSizeChange(float x, float y)
{
	shape->setSize(sf::Vector2f(x * (_height / 100), y *(_width / 100)));
	shape->setPosition(sf::Vector2f(x * (_posX / 100), y *(_posY / 100)));

	content->setPosX(_posX);
	content->setPosY(_posY);
	content->OnWindowsSizeChange(x, y);
	content->originInMidle();
	
}

void		UIButton::OnClick(void *arg){
	LOG("OnClick");
	try
	{
		_onClickCallBack(this, arg);
	}
	catch(const std::bad_function_call& ex)
	{
		ERROR(ex.what());
	}

}


UIButton	*UIButton::NewButton(std::string Tag, float  PosX, float PosY, float Height, float Width,
	int background, int foreground, int border, std::string Text,
	std::function<void(void*, void*)> onClickCallBack)
{
	return new UIButton(Tag, PosX, PosY, Height, Width, background, foreground, border, Text, onClickCallBack);
}

void		UIButton::setContent(std::string value)
{
	this->content->setText(value);
}