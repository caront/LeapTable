#include "Core.hpp"
#include "Log.hpp"

Core::Core(std::string folderpath, CallBackListener *callbacklisternet)
{

	collectionElement = new CollectionElement(folderpath, callbacklisternet);
	controller = new Controller(this);
	event = new EventListener();
}

Core::~Core()
{
}

void Core::Init()
{
	collectionElement->InitCollection();
	controller->Init(collectionElement->getMenu());
	controller->LoadPage(collectionElement->getMainPage());
}

void Core::Run()
{
	controller->Render(event->menushow);
	event->Init();
	while (controller->IsWindowOpen())
	{
		event->CheckEvent(this, controller->page);
		
		controller->Render(event->menushow);
		controller->Event(event->menushow);	
	}

}

void Core::Finish()
{

}

/*
Object3D	*Core::GetFromCurent()
{

}*/

void Core::NavigateTo(std::string pageTag)
{
	Page *page = collectionElement->getPageByTag(pageTag);
	controller->LoadPage(page);
}