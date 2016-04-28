#include "Core.hpp"
#include <unistd.h>

Core::Core()
{
	_controler = new Controler();
	_coreShared = new CoreShared();
	_output = new Output();
	_gestureList = new GestureList(*_controler, *_coreShared);
	_pointer = new Pointer();
}

Core::~Core()
{
	delete _controler;
}

void Core::Run()
{
	Leap::Frame frame;
	while (true)
	{
		frame = _controler->getFrame();
		
   		Leap::GestureList gestures = frame.gestures();
		for(Leap::GestureList::const_iterator gl = gestures.begin(); gl != gestures.end(); gl++)
		    _gestureList->Search((*gl));
		_pointer->exec(frame);
		usleep(5000);
   	}
}