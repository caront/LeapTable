#include "BottomSlide.hpp"

BottomSlide::BottomSlide(Controler 	&controler, CoreShared &coreShared)
 : Gesture(controler, coreShared, 2, 0, 1, 10){}

BottomSlide::~BottomSlide(){}

bool BottomSlide::isThat(Leap::SwipeGesture sG)
{
	Leap::Vector direction = sG.direction();
	if (direction.x < 0)
		return true;
	return false;
}

void BottomSlide::execute(){
	system("xdotool key ctrl+alt+Down");
}

