#ifndef __UP_SLIDE_H__
#define __UP_SLIDE_H__

#include "Gesture.hpp"

class UpSlide : public Gesture {
public:
	UpSlide(Controler &controler);
	~UpSlide();
	
	virtual bool 	isThat(Leap::SwipeGesture sG);
	virtual void 	execute();


};

#endif