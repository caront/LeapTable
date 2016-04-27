#ifndef __SCREEN_INFO_H__
#define __SCREEN_INFO_H__ 

#include <X11/Xlib.h>

class ScreenInfo
{

public:
	ScreenInfo();
	~ScreenInfo();

	static Screen *GetScreenInfo();
	
};

#endif