#include "Core.hpp"

Core::Core(std::string folderpath)
{

	collectionElement = new CollectionElement(folderpath);
	controller = new Controller(this);
}

Core::~Core()
{
}

void Core::Init()
{
	collectionElement->InitCollection();
	controller->Init();
	controller->LoadPage(collectionElement->getMainPage());
	//this->NavigateTo("PageOne");
}

void Core::Run()
{
	while (controller->IsWindowOpen())
	{
		controller->Render();
		controller->Event();
	}

}

void Core::Finish()
{

}


void Core::NavigateTo(std::string pageTag)
{
	Page *page = collectionElement->getPageByTag(pageTag);
	controller->LoadPage(page);

}