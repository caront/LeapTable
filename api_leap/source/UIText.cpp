#include "UIText.hpp"


UIText::UIText(std::string Tag, float PosX, float PosY,
	std::string text, sf::Font *font, int textSize, int forground)
	: UIObject(Tag, PosX, PosY, 0, 0)
	, _textSize(textSize)
	, _font(font)
{
	_text = text;
	_foreground.c = forground;
	this->InitiazeCompoment();
}


UIText::~UIText()
{
}

void		UIText::InitiazeCompoment()
{
	_textShape = new sf::Text();
	_textShape->setString(_text);
	_textShape->setCharacterSize(_textSize);
	_textShape->setFont(*_font);
	_textShape->setColor(sf::Color(_foreground.argb.r, _foreground.argb.g, _foreground.argb.b, _foreground.argb.a));
}
void		UIText::Draw(sf::RenderWindow *window)
{
	window->draw(*_textShape);
}

void		UIText::OnWindowsSizeChange(float x, float y)
{
	_textShape->setPosition(sf::Vector2f(x * (_posX / 100), y *(_posY / 100)));
}

void		UIText::Reset()
{

}

void		UIText::setText(std::string value){
	_text = value;
	_textShape->setString(value);
}
void		UIText::setTextSize(int value){
	_textSize = value;
	_textShape->setCharacterSize(value);
}
void		UIText::setTextFont(sf::Font *value){
	_font = value;
	_textShape->setFont(*value);
}
void		UIText::setForground(int value){
	_foreground.c = value;
	_textShape->setColor(sf::Color(_foreground.argb.r, _foreground.argb.g, _foreground.argb.b, _foreground.argb.a));
}
void		UIText::setForground(Color value){
	_foreground = value;
	_textShape->setColor(sf::Color(_foreground.argb.r, _foreground.argb.g, _foreground.argb.b, _foreground.argb.a));
}

std::string	UIText::getText() const{
	return _text;
}
int			UIText::getTextSize() const{
	return _textSize;
}
sf::Font	UIText::getTextFont() const{
	return *_font;
}
Color		UIText::getForground() const{
	return _foreground;
}

void 		UIText::originInMidle()
{
	setOrigin(_textShape->getScale().x /2, _textShape->getScale().y /2);
}

void 		UIText::setOrigin(float x, float y)
{
	_textShape->setOrigin(x, y);
}

UIText		*UIText::NewText(std::string Tag, float PosX, float PosY,
	std::string text, sf::Font *font, int textSize, int forground){
	return new UIText(Tag, PosX, PosY, text, font, textSize, forground);
}