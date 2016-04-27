#include "Output.hpp"

Output::Output()
{}

Output::~Output()
{}

void Output::PrintHand(Leap::Hand hand){
 	Leap::Vector handCenter = hand.palmPosition();
 	std::cout << "Hand " << std::endl;
 	PrintVector(handCenter);
 	std::cout<< std::endl;
}

void Output::PrintFingerList(Leap::FingerList fingers){

}

void Output::PrintFinger(Leap::Vector finger){

}

void Output::PrintFinger(int number, Leap::Vector finger){
	std::cout << "finger :" << number << std::endl;

	PrintVector(finger);
	std::cout << std::endl;
}

void Output::PrintVector(Leap::Vector vector)
{
	std::cout << " pos x : " << vector.x;
	std::cout << " pos y : " << vector.y;
	std::cout << " pos z : " << vector.z;
}
