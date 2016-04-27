#include "Pointer.hpp"

Pointer::Pointer(){}

Pointer::~Pointer(){}

void Pointer::exec(Leap::Frame frame)
{
	if (frame.hands().isEmpty())
		return;
  SetPos(frame.hands()[0].palmPosition());
    
}

void Pointer::SetPos(Leap::Vector newPos)
{
    std::string cmd = "xdotool mousemove ";

    cmd += std::to_string(POSX(newPos.x * 1.5));
    cmd += " ";
    cmd += std::to_string(POSY(newPos.z  * 1.5));

    system(cmd.c_str()); 
}