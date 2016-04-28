#include "GestureList.hpp"

GestureList::GestureList(Controler 	&controler, CoreShared &coreShared)
	: _controler(controler)
{
	_list.push_back(new LeftSlide(controler, coreShared));
	_list.push_back(new RightSlide(controler, coreShared));
	_list.push_back(new DownSlide(controler, coreShared));
	_list.push_back(new UpSlide(controler, coreShared));
	/*_list.push_back(new TopSlide(controler));
	_list.push_back(new BottomSlide(controler));*/
	_cooldown = 0;
}

GestureList::~GestureList(){}

bool GestureList::Search(Leap::Gesture leapGesture)
{
	_cooldown--;
	if (leapGesture.type() == Leap::Gesture::TYPE_KEY_TAP){
		_tap.exec(leapGesture);
		return true;
	}
	if (leapGesture.type() == Leap::Gesture::TYPE_CIRCLE){
		_rotation.exec(leapGesture);
		return true;
	}
	if (leapGesture.type() == Leap::Gesture::TYPE_SWIPE && _cooldown <= 0){
		Leap::SwipeGesture swipe = leapGesture;
		for (Gesture *g : _list)
		{
			if (g->isThat(swipe) == true)
			{
				g->execute();
				_cooldown = COOLDOWN;
				return true;
			}
		}
	}
	return false;
}
