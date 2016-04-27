//page.hpp

#ifndef __PAGE_H__
#define __PAGE_H__

#include "UIObjectList.hpp"
#include "UIButton.hpp"
#include "CallBackListener.hpp"
#include "Core.hpp"

class Core;

class Page
{
private:

	sf::RectangleShape	*background;
	UIObjectList		*_listObject;
	std::string			_tag;
	Color				_background;

public:
	Page();
	~Page();


	void Init(float x, float y);
	void Draw(sf::RenderWindow *window);
	void OnWindowSizeChange(float x, float y);

	void	AddElement(UIObject *object);

	UIObject *GetObjectOnFocus(sf::Event *event);
	UIObject *GetObjectOnClick(sf::Event *event);

	UIObjectList	*GetObjectList();

	void SetObjectList(UIObjectList *obj);
	
	std::string getTag() const;

	void		setTag(std::string value);
	void		setBackground(int value);
};

#endif