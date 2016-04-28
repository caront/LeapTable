#include "Controller.hpp"



void OnResize(int nw, int nh) {
  glViewport(0, 0, nw, nh);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, float(nw)/nh, 0.1, 100);
  glMatrixMode(GL_MODELVIEW);
}

Controller::Controller(Core *core)
	:_core(core)
{
	menushadow = new sf::RectangleShape();
}


Controller::~Controller()
{

}

void CallBacktoto(void *arg, void *tutu)
{
	LOG("CallBack Menu");
}

void Controller::Init(UIMenu *menu)
{

	//window = new sf::RenderWindow(sf::VideoMode(ScreenInfo::GetScreenInfo()->width, ScreenInfo::GetScreenInfo()->height, 32), "name", sf::Style::Fullscreen);
	window = new sf::RenderWindow(sf::VideoMode(ScreenInfo::GetScreenInfo()->width,ScreenInfo::GetScreenInfo()->height, 32), "name");
	openGlUtils = new OpenGlUtils(*window);
	this->menu = menu;
	this->menu->Init(window);
	menushadow->setSize(sf::Vector2f(static_cast<float> (window->getSize().x), static_cast<float> (window->getSize().y)));
	menushadow->setFillColor(sf::Color(42, 42, 42, 150));
	object3D = new Object3D("tag", "./object.obj", sf::Vector3f(-5, 0, -50), sf::Vector3f(0, 0, 0));
	object3D->Init();

}

void Controller::LoadPage(Page *page)
{
	this->page = page;
	page->Init(static_cast<float> (window->getSize().x), static_cast<float> (window->getSize().y));
}

void Controller::Render(bool showMenu)
{
	openGlUtils->Clean(object3D);
	openGlUtils->Push();
	page->Draw(window);
	if (showMenu)
		ShowMenu();
	openGlUtils->Pop();
	if (page->getTag() != "PageOne")
		object3D->Draw();
	window->display();
}

void Controller::Event(bool menuEvent)
{
	if (menuEvent)
		EventMenu();
	else
		EventPage();
}	

void Controller::EventPage()
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
		case sf::Event::MouseMoved:
			if ((obj = page->GetObjectOnFocus(&event)) != NULL)
				obj->OnFocus(window);
		case sf::Event::MouseButtonReleased:
			if ((obj = page->GetObjectOnClick(&event)) != NULL)
				obj->OnClick(_core);
		case sf::Event::Resized:
			 OnResize(event.size.width, event.size.height);
		default:
			break;
		}
	}
}

void Controller::EventMenu()
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
		case sf::Event::MouseMoved:
			if ((obj = menu->GetObjectOnFocus(&event)) != NULL)
				obj->OnFocus(window);
		case sf::Event::MouseButtonReleased:
			if ((obj = menu->GetObjectOnClick(&event)) != NULL)
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

void Controller::ShowMenu()
{
	window->draw(*menushadow);
	menu->Draw(window);
}
