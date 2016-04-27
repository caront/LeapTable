#include "Rotation.hpp"

Rotation::Rotation(){}

Rotation::~Rotation(){}

void Rotation::exec(Leap::Gesture gesture)
{
	Leap::CircleGesture circle = gesture;
	if (circle.pointable().direction().angleTo(circle.normal()) <= Leap::PI/2) {
    	std::cout << "up" <<std::endl;
    	system("xdotool click 4");
	}
	else	{
    	std::cout << "down" <<std::endl;
    	system("xdotool click 5");
	}
}