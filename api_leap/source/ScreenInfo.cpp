#include "ScreenInfo.hpp"

ScreenInfo::ScreenInfo(){}
ScreenInfo::~ScreenInfo(){}

Screen *ScreenInfo::GetScreenInfo(){	
	Display* disp = XOpenDisplay(NULL);
	Screen*  scrn = DefaultScreenOfDisplay(disp);
	return scrn;
}