#include "callback.hpp"

#include "apileap.hpp"

void		OnClickTest(void *sender, void *arg)
{
	UIButton *button = static_cast<UIButton*>(sender);

	std::cout << "on ClickText : " << button->getTag() << std::endl;
}


void	OnButtonClick_1(void *sender, void*args)
{
	UIButton *button = static_cast<UIButton*>(sender);

	std::cout << "OnButtonClick_1 : " << button->getTag() << std::endl;

	button->setPosX(button->getPosX() + 10);
}

void	OnButtonClick_2(void *sender, void*args)
{
	UIButton *button = static_cast<UIButton*>(sender);

	button->setContent("Click :)");
}

void	OnButtonClick_3(void *sender, void*args)
{
	static int i = 0;
	UIButton *button = static_cast<UIButton*>(sender);
	Core *core = static_cast<Core *>(args);
	UIText	*text = static_cast<UIText*>(core->collectionElement->getObjectByTag("Text"));

	text->setText("pony time x " + std::to_string(i));

	i++;	
}

void	OnButtonClick_4(void *sender, void*args)
{
	Core *core = static_cast<Core *>(args);
	
	core->NavigateTo("PageTwo");
}