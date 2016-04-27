#ifndef __CONTROLER_H__
#define __CONTROLER_H__

#include "Leap.h"

class Controler
{
private:
	Leap::Listener _listener;
  	Leap::Controller _controller;

public:
	Controler();
	~Controler();

	Leap::Frame getFrame();

	
};

#endif