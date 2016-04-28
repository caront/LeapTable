#include "UIImage.hpp"
#include "Log.hpp"

UIImage::UIImage(std::string Tag, float PosX, float PosY, float sizeX, float sizeY, std::string filepath)
	: UIObject(Tag, PosX, PosY, sizeX, sizeY)
	, _file(filepath)
{
	this->InitiazeCompoment();
}

UIImage::~UIImage(){}

void 	UIImage::InitiazeCompoment()
{
	if (!_image.loadFromFile(_file))
	{
		ERROR("[UIImage]Can't open Image");
	}
	_sprite.setTexture(_image);
	_sprite.setScale(_height, _width);
}

void		UIImage::Draw(sf::RenderWindow *window)
{
	window->draw(_sprite);
}

void		UIImage::OnWindowsSizeChange(float x, float y)
{
	_sprite.setPosition(sf::Vector2f(x * (_posX / 100), y *(_posY / 100)));
}

void UIImage::Reset(){}

std::string UIImage::getFile()
{
	return _file;
}

void 		UIImage::setFile(std::string value)
{
	_file = value;
	InitiazeCompoment();
}

UIImage		*UIImage::NewImage(std::string Tag, float PosX, float PosY, float sizeX, float sizeY, std::string file)
{
	return new UIImage(Tag, PosX, PosY, sizeX, sizeY, file);
}