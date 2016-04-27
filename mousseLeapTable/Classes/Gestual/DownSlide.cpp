#include "DownSlide.hpp"

DownSlide::DownSlide(Controler 	&controler) : Gesture(controler, 2, 0, 1, 10){}

DownSlide::~DownSlide(){}

bool DownSlide::isThat(Leap::SwipeGesture sG)
{
	Leap::Vector direction = sG.direction();
	

	if (direction.z > 0 && ( direction.x < MAXRANGE && direction.x > MINRANGE))
	{
		return true;
	}
	return false;
}

void DownSlide::execute(){
	system("xdotool key ctrl+alt+Down");
}

