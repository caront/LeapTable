#include "UIMenuElement.hpp"

UIMenuElement::UIMenuElement(std::string tag, std::string text, std::function<void(void*, void*)> onClickCallBack, int color, int forground)
	: UiButtonCircle(tag, 0, 0, 5, color, forground, color, text, onClickCallBack)
{

}

UIMenuElement::~UIMenuElement(){}