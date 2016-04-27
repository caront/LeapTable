#include "UpSlide.hpp"

UpSlide::UpSlide(Controler 	&controler) : Gesture(controler, 2, 0, 1, 10){}

UpSlide::~UpSlide(){}

bool UpSlide::isThat(Leap::SwipeGesture sG)
{
	Leap::Vector direction = sG.direction();
	if (direction.z < 0)
		return true;
	return false;
}

void UpSlide::execute(){
	std::cout << "Up Slide" << std::endl;
	system("xdotool click 4");
}

