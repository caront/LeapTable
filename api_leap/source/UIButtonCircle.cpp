#include "UIButtonCircle.hpp"
#include "Log.hpp"

UiButtonCircle::UiButtonCircle(std::string Tag, float PosX, float PosY, float Radius,
	int background, int foreground, int border, std::string Text, std::function<void(void*, void*)> onClickCallBack)
	: UiButtonCircle(Tag, PosX, PosY, Radius, background, foreground, border, Text)

{
	_onClickCallBack = onClickCallBack;
}

UiButtonCircle::UiButtonCircle(std::string Tag, float PosX, float PosY, float Radius, 
	int background, int foreground, int border, std::string Text)
	: UIObject(Tag, PosX, PosY, Radius, 0)

{
	_background.c = background;
	_foreground.c = foreground;
	_border.c = border;
	_text = Text;
	this->InitiazeCompoment();
}

UiButtonCircle::~UiButtonCircle()
{
}

void		UiButtonCircle::InitiazeCompoment()
{
	sf::Font *font = new sf::Font();
	const std::string fontpath = "./window/Assets/Fonts/Aaargh.ttf";
	if (!font->loadFromFile(fontpath))
		getchar();
	shape = new sf::CircleShape();
	shape->setRadius(_height);
	shape->setPosition(sf::Vector2f((float) _posX, (float) _posY));
	shape->setOutlineThickness(3);
	content = new UIText("", _posX + _height / 2, _posY + _height / 2, _text, font, 30, _foreground.c);
	content->originInMidle();
	this->Reset();
}

void		UiButtonCircle::Draw(sf::RenderWindow *window){
	if (_UIPropChanged)
		OnWindowsSizeChange(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y));
	window->draw(*shape);
	content->Draw(window);
	_UIPropChanged = false;
}



void		UiButtonCircle::Reset(){
	if (_isFocus)
	{
		shape->setOutlineColor(sf::Color(_background.argb.r, _background.argb.g, _background.argb.b, _background.argb.a));
		shape->setFillColor(sf::Color(_foreground.argb.r, _foreground.argb.g, _foreground.argb.b, _foreground.argb.a));
		content->setForground(_border);
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

bool		UiButtonCircle::OnClick(sf::Event *event){
	_isClick = false;
	if (event->mouseButton.x > shape->getPosition().x &&
		event->mouseButton.x <  shape->getPosition().x + shape->getRadius())
	{
		if (event->mouseButton.y > shape->getPosition().y &&
			event->mouseButton.y <  shape->getPosition().y + shape->getRadius())
			_isClick = true;
	}
	return _isClick;
}

bool		UiButtonCircle::OnFocus(sf::Event *event){
	_isFocus = false;
	if (event->mouseMove.x > shape->getPosition().x &&
		event->mouseMove.x <  shape->getPosition().x + shape->getRadius())
	{
		if (event->mouseMove.y > shape->getPosition().y &&
			event->mouseMove.y < shape->getPosition().y + shape->getRadius())
			_isFocus = true;
	}
	return _isFocus;
}


void		UiButtonCircle::OnFocus(sf::RenderWindow *window){
}

void		UiButtonCircle::OnWindowsSizeChange(float x, float y)
{
	shape->setRadius(x * (_height / 100));
	shape->setPosition(sf::Vector2f(x * (_posX / 100), y *(_posY / 100)));
	content->setPosX(_posX + _height / 2);
	content->setPosY(_posY + _height / 2);
	content->OnWindowsSizeChange(x, y);
	content->originInMidle();
}

void		UiButtonCircle::OnClick(void *arg){
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


UiButtonCircle	*UiButtonCircle::NewButton(std::string Tag, float  PosX, float PosY, float Radius,
	int background, int foreground, int border, std::string Text,
	std::function<void(void*, void*)> onClickCallBack)
{
	return new UiButtonCircle(Tag, PosX, PosY, Radius, background, foreground, border, Text, onClickCallBack);
}

void		UiButtonCircle::setContent(std::string value)
{
	this->content->setText(value);
}