#ifndef __POINTER_H__
#define __POINTER_H__


#include "Leap.h"

#define SCREENSIZEX 1920
#define SCREENSIZEY 1080

#define POSX(x) ((x * SCREENSIZEX) + (200  * SCREENSIZEX)) / 400
#define POSY(y) (y * SCREENSIZEY) / 200
//#define GETSCRENPOSX(x) 


class Pointer
{
public:
	Pointer();
	~Pointer();

	void exec(Leap::Frame frame);	

	static void SetPos(Leap::Vector newPos);
};

#endif