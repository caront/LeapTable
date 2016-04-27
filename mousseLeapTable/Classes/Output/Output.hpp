#ifndef __OUTPUT_H__
#define __OUTPUT_H__

#include "Leap.h"

class Output
{

public:
	Output();
	~Output();

	void PrintHand(Leap::Hand hand);
	void PrintFingerList(Leap::FingerList fingers);
	void PrintFinger(Leap::Vector finger);
	void PrintFinger(int number, Leap::Vector finger);
	void PrintVector(Leap::Vector vector);
};

#endif