#ifndef __GESTURE_H__
#define __GESTURE_H__

#include "Leap.h"
#include "Controler.hpp"
#include "Output.hpp"

#include "CoreShared.hpp"

#define MAXRANGE 0.1
#define MINRANGE -MAXRANGE



class Gesture {
protected:
	int 		_fingerNbrR;
	int 		_fingerNbrL;
	int 		_handNbr;
	int 		_tick;
	Controler 	&_controler;
	CoreShared 	&_coreShared;
	Output 		_output;


public:
	Gesture(Controler &controler, CoreShared &coreShared, int fingerNbrR,int fingerNbrL, int handNbr, int tick);
	~Gesture();

	virtual bool 	isThat(Leap::SwipeGesture sG) = 0;
	virtual void 	execute() = 0;
	
};

#endif