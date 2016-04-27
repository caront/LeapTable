#ifndef __TAP_H__
#define __TAP_H__

#include "Leap.h"
#include "Gesture.hpp"

class Tap
{
public:
	Tap();
	~Tap();
	
	void exec(Leap::Gesture gesture);
};

#endif