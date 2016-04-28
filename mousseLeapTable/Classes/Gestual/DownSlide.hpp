#ifndef __DOWN_SLIDE_H__
#define __DOWN_SLIDE_H__

#include "Gesture.hpp"

class DownSlide : public Gesture {

public:
	DownSlide(Controler &controler, CoreShared &coreShared);
	~DownSlide();
	
	virtual bool 	isThat(Leap::SwipeGesture sG);
	virtual void 	execute();


};

#endif