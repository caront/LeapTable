#ifndef __ROTATION_H__
#define __ROTATION_H__

#include "Leap.h"

class Rotation {
public:
	Rotation();
	~Rotation();

	void exec(Leap::Gesture gesture);
	
};

#endif