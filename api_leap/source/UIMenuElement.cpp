#include "UIMenuElement.hpp"

UIMenuElement::UIMenuElement(std::string tag, std::string text, std::function<void(void*, void*)> onClickCallBack)
	: UiButtonCircle(tag, 0, 0, 20, 0xffffffff, 0xff000000, 0xff000000, text, onClickCallBack)
{

}

UIMenuElement::~UIMenuElement(){}