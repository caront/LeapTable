#ifndef __RIGHT_SLIDE_H__
#define __RIGHT_SLIDE_H__

#include "Gesture.hpp"

class RightSlide : public Gesture {
public:
	RightSlide(Controler &controler);
	~RightSlide();
	
	virtual bool 	isThat(Leap::SwipeGesture sG);
	virtual void 	execute();

};

#endif