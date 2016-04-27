#ifndef __GESTURE_LIST__
#define __GESTURE_LIST__

#include <list>
#include "Gesture.hpp"
#include "LeftSlide.hpp"
#include "DownSlide.hpp"
#include "UpSlide.hpp"
#include "RightSlide.hpp"
#include "TopSlide.hpp"
#include "BottomSlide.hpp"
#include "Output.hpp"
#include "Tap.hpp"
#include "Rotation.hpp"

#define COOLDOWN 30

class GestureList {
private:

	std::list<Gesture *> 	_list;
	Tap 					_tap;
	Output 					_output;
	Controler 				&_controler;
	Rotation 				_rotation;
	int 					_cooldown;

public:
	GestureList(Controler 	&controler);
	~GestureList();

	bool Search(Leap::Gesture leapGesture);
	
};

#endif