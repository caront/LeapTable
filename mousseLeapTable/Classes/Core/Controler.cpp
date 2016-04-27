#include "Controler.hpp"

Controler::Controler()
{
	_controller.addListener(_listener);
	_controller.enableGesture(Leap::Gesture::TYPE_CIRCLE);
	_controller.enableGesture(Leap::Gesture::TYPE_KEY_TAP);
	_controller.enableGesture(Leap::Gesture::TYPE_SCREEN_TAP);
	_controller.enableGesture(Leap::Gesture::TYPE_SWIPE);
	_controller.config().setFloat("Gesture.Circle.MinRadius", 30.0);
	_controller.config().setFloat("Gesture.Circle.MinArc", 0.75);
	_controller.config().setFloat("Gesture.Swipe.MinLength", 3.0);
	_controller.config().setFloat("Gesture.Swipe.MinVelocity", 3.0);
	_controller.config().setFloat("Gesture.KeyTap.MinDownVelocity", 1.0);
	_controller.config().setFloat("Gesture.KeyTap.HistorySeconds", 1);
	_controller.config().setFloat("Gesture.KeyTap.MinDistance", 0.2);
	_controller.config().save();
}

Controler::~Controler()
{
	_controller.removeListener(_listener);
}

Leap::Frame Controler::getFrame()
{
	return _controller.frame();
}