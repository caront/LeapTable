#include "Core.hpp"
#include <unistd.h>

Core::Core()
{
	_controler = new Controler();
	_output = new Output();
	_gestureList = new GestureList(*_controler);
	_pointer = new Pointer();
}

Core::~Core()
{
	delete _controler;
}

void Core::Run()
{
	Leap::Frame frame;
	while (1)
	{
		frame = _controler->getFrame();
		
   		//std::cout << "new Gesture" << std::endl;
   		Leap::GestureList gestures = frame.gestures();
		for(Leap::GestureList::const_iterator gl = gestures.begin(); gl != gestures.end(); gl++)
		{
		    _gestureList->Search((*gl));
		}
		_pointer->exec(frame);
		//std::cout << "cooldown : " << _gestureList->cooldown << std::endl;
		usleep(5000);
   	}
}