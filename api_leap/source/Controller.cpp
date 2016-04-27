#include "Controller.hpp"
//#include "CallBack.h"

Controller::Controller(Core *core)
	:_core(core)
{

}


Controller::~Controller()
{

}

void Controller::Init()
{

	//window = new sf::RenderWindow(sf::VideoMode(ScreenInfo::GetScreenInfo()->width, ScreenInfo::GetScreenInfo()->height, 32), "name", sf::Style::Fullscreen);
	window = new sf::RenderWindow(sf::VideoMode(ScreenInfo::GetScreenInfo()->width, ScreenInfo::GetScreenInfo()->height, 32), "name");


}

void Controller::LoadPage(Page *page)
{
	this->page = page;
	page->Init(static_cast<float> (window->getSize().x), static_cast<float> (window->getSize().y));
	//page = reader->ReadPageDoc("PageOne.xml", callBackListener);
	//page->Init(static_cast<float> (window->getSize().x), static_cast<float> (window->getSize().y), callBackListener);
}

void Controller::Render()
{
	page->Draw(window);
	window->display();
}

void Controller::Event()
{
	sf::Event event;
	UIObject *obj;

	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::Resized:
			page->OnWindowSizeChange(static_cast<float> (window->getSize().x), static_cast<float> (window->getSize().y));
			break;
		case sf::Event::MouseMoved:
			if ((obj = page->GetObjectOnFocus(&event)) != NULL)
				obj->OnFocus(window);
		case sf::Event::MouseButtonPressed:
			page->GetObjectOnClick(&event);
		case sf::Event::MouseButtonReleased:
			if ((obj = page->GetObjectOnClick(&event)) != NULL)
				obj->OnClick(_core);
		default:
			break;
		}
	}
}

bool Controller::IsWindowOpen()
{
	return window->isOpen();
}
