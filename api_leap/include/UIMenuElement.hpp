#ifndef __UIMENU_ELEMENT_H__
#define __UIMENU_ELEMENT_H__

#include "UIButtonCircle.hpp"
#include <functional>

class UIMenuElement : public UiButtonCircle
{
public:
	UIMenuElement(std::string tag,
	 std::string text, std::function<void(void*, void*)> onClickCallBack, int color, int forground);
	~UIMenuElement();
	
};

#endif