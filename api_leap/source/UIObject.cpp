#include "UIObject.hpp"


UIObject::UIObject()
	: _posX(0)
	, _posY(0)
	, _height(0)
	, _width(0)
	, _isFocus(false)
	, _isClick(false)
	, _UIPropChanged(false)
{

}
UIObject::UIObject(std::string Tag, float PosX, float PosY, float Height, float Weight)
	: _posX(PosX)
	, _posY(PosY)
	, _height(Height)
	, _width(Weight)
	, _tag(Tag)
	, _isFocus(false)
	, _isClick(false)
	, _UIPropChanged(false)
{
}



UIObject::~UIObject()
{
}



float UIObject::getHeight() const {
	return _height;
}

float UIObject::getWidth() const {
	return _width;
}

float UIObject::getPosX() const {
	return _posX;
}

float UIObject::getPosY() const {
	return _posY;
}

std::string UIObject::getTag() const{
	return _tag;
}

void	UIObject::setPosX(float value){
	_posX = value;
	_UIPropChanged = true;
}

void	UIObject::setPosY(float value){
	_posY = value;
	_UIPropChanged = true;
}

void	UIObject::setHeight(float value){
	_height = value;
	_UIPropChanged = true;
}

void	UIObject::setWitdh(float value){
	_width = value;
	_UIPropChanged = true;
}