
#include "apileap.hpp"

#include "callback.hpp"

void ExitEvent(void *arg1, void *arg2)
{
	LOG("EXIT");
	Core *core = (Core *)arg1;
	Page *page = (Page *)arg2;

	LOG(page->getTag());
}

void ShowMenu(void *arg1, void *arg2)
{
	LOG("SHOW");
}

void HideMenu(void *arg1, void *arg2)
{
	LOG("HIDE");
}




int main()
{
	CallBackListener *callBackListener = new CallBackListener();

	callBackListener->Add("OnButtonClick_1", OnButtonClick_1);
	callBackListener->Add("OnButtonClick_2", OnButtonClick_2);
	callBackListener->Add("OnButtonClick_3", OnButtonClick_3);
	callBackListener->Add("OnButtonClick_4", OnButtonClick_4);
	callBackListener->Add("GoBack", GoBack);
	callBackListener->Add("UpModel", UpModel);
	callBackListener->Add("DownModel", DownModel);
	callBackListener->Add("LeftModel", LeftModel);
	callBackListener->Add("RightModel", RightModel);
	callBackListener->Add("GoPageCroiseur", GoPageCroiseur);
	callBackListener->Add("GoPageLitesaber", GoPageLitesaber);

	Core *core = new Core("window", callBackListener);

 	core->event->setCloseEvent(ExitEvent);
	core->event->setShowMenuEvent(ShowMenu);
 	core->event->setHideMenuEvent(HideMenu);

	core->Init();
	core->Run();

	return 0;
}