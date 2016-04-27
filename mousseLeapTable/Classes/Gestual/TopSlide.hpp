#ifndef __TOP_SLIDE_H__
#define __TOP_SLIDE_H__

#include "Gesture.hpp"

class TopSlide : public Gesture {
public:
	TopSlide(Controler &controler);
	~TopSlide();
	
	virtual bool 	isThat(Leap::SwipeGesture sG);
	virtual void 	execute();

};

#endif