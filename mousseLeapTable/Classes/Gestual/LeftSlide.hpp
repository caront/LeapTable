#ifndef __LEFT_SLIDE_H__
#define __LEFT_SLIDE_H__

#include "Gesture.hpp"

class LeftSlide : public Gesture {
public:
	LeftSlide(Controler &controler, CoreShared &coreShared);
	~LeftSlide();
	
	virtual bool 	isThat(Leap::SwipeGesture sG);
	virtual void 	execute();


};

#endif