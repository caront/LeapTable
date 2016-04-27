#include "LeftSlide.hpp"

#include <unistd.h>

LeftSlide::LeftSlide(Controler 	&controler) : Gesture(controler, 2, 0, 1, 10){}

LeftSlide::~LeftSlide(){}

bool LeftSlide::isThat(Leap::SwipeGesture sG)
{
	Leap::Vector direction = sG.direction();
	
	if (direction.x < 0 && ( direction.z < MAXRANGE && direction.z > MINRANGE))
		return true;
	return false;
}

void LeftSlide::execute(){
	system("xdotool key ctrl+alt+Left");
//	usleep(50000);
}

