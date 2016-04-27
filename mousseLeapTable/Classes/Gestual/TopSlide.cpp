#include "TopSlide.hpp"

TopSlide::TopSlide(Controler 	&controler) : Gesture(controler, 2, 0, 1, 10){}

TopSlide::~TopSlide(){}

bool TopSlide::isThat(Leap::SwipeGesture sG)
{
	Leap::Vector direction = sG.direction();
	if (direction.y > 0)
		return true;
	return false;
}

void TopSlide::execute(){
	std::cout << "Top Slide" << std::endl;
}

