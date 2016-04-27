#include "Gesture.hpp"

Gesture::Gesture(Controler 	&controler, int fingerNbrR,int fingerNbrL, int handNbr, int tick)
	: _fingerNbrR(fingerNbrR)
	, _fingerNbrL(fingerNbrL)
	, _handNbr(handNbr)
	, _tick(tick)
 	, _controler(controler)
{

}

Gesture::~Gesture(){}