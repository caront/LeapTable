#include "Tap.hpp"

#include "Pointer.hpp"

Tap::Tap(){}

Tap::~Tap(){}

void Tap::exec(Leap::Gesture gesture)
{
	Leap::KeyTapGesture keytap = gesture;

	Leap::PointableList pointables = keytap.pointables();
	if (!pointables.isEmpty())
	{
		if (pointables[0].isFinger())
		{
			//Pointer::SetPos(pointables[0].stabilizedTipPosition());
			system("xdotool click 1");
		}
	}
}