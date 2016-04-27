#ifndef __CORE_H__
#define __CORE_H__

#include "Leap.h"
#include "Controler.hpp"
#include "Output.hpp"
#include "GestureList.hpp"
#include "Pointer.hpp"

class Core {

private:
	Controler 		*_controler;
	Output 			*_output;
	GestureList 	*_gestureList;
	Pointer 		*_pointer;
	

public:
	Core();
	~Core();

	void Run();

};

#endif