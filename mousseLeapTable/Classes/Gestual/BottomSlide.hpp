#ifndef __BOTTOM_SLIDE_H__
#define __BOTTOM_SLIDE_H__

#include "Gesture.hpp"

class BottomSlide : public Gesture {
public:
	BottomSlide(Controler &controler,CoreShared &coreShared);
	~BottomSlide();
	
	virtual bool 	isThat(Leap::SwipeGesture sG);
	virtual void 	execute();

};

#endif