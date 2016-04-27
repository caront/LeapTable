#ifndef __UIMENU_ELEMENT_H__
#define __UIMENU_ELEMENT_H__

#include "UIButtonCircle.hpp"
#include <functional>

class UIMenuElement : UiButtonCircle
{
public:
	UIMenuElement(td::string tag,
	 std::string text, std::function<void(void*, void*)> onClickCallBack);
	~UIMenuElement();
	
};

#endif