#include "RightSlide.hpp"
#include <unistd.h>

RightSlide::RightSlide(Controler &controler, CoreShared &coreShared) 
	: Gesture(controler, coreShared, 2, 0, 1, 10){}

RightSlide::~RightSlide(){}

bool RightSlide::isThat(Leap::SwipeGesture sG)
{
	Leap::Vector direction = sG.direction();
	if (direction.x > 0 && ( direction.z < MAXRANGE && direction.z > MINRANGE))
		return true;
	return false;
}

void RightSlide::execute(){
	system("xdotool key ctrl+alt+Right");
	//usleep(50000);
}
