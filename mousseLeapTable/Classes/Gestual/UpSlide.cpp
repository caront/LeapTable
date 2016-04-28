#include "UpSlide.hpp"

UpSlide::UpSlide(Controler 	&controler, CoreShared &coreShared) 
: Gesture(controler, coreShared, 2, 0, 1, 10){}

UpSlide::~UpSlide(){}

bool UpSlide::isThat(Leap::SwipeGesture sG)
{
	Leap::Vector direction = sG.direction();
	if (direction.z < 0  && ( direction.x < MAXRANGE && direction.x > MINRANGE))
		return true;
	return false;
}

void UpSlide::execute(){
	_coreShared.SendToFocused(SHOWMENU);
}

