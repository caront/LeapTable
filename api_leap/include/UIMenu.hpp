#ifndef __UIMENU_H__
#define __UIMENU_H__ 

#include "UIMenuElement.hpp"


class UIMenu
{
private:
	UIMenuElement *_up;
	UIMenuElement *_down;
	UIMenuElement *_left;
	UIMenuElement *_right;

public:
	UIMenu();
	~UIMenu();
	
};

#endif
