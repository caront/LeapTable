#ifndef __CORE_H__
#define __CORE_H__

#include "Leap.h"
#include "Controler.hpp"
#include "Output.hpp"
#include "GestureList.hpp"
#include "Pointer.hpp"
#include "CoreShared.hpp"

class Core {

private:
	Controler 		*_controler;
	Output 			*_output;
	GestureList 	*_gestureList;
	Pointer 		*_pointer;
	CoreShared 		*_coreShared;

public:
	Core();
	~Core();

	void Run();

};

#endif