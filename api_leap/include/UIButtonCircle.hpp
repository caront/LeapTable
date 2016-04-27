#ifndef __UIBUTTON_CIRCLE_H__
#define __UIBUTTON_CIRCLE_H__


#include "UIObject.hpp"
#include "Color.hh"
#include "UIText.hpp"
#include <functional>

class UiButtonCircle : public UIObject
{
private:

	Color				_background;
	Color				_foreground;
	Color				_border;

	std::string			_text;

	sf::CircleShape *shape;
	std::function<void(void*, void*)> _onClickCallBack;
	std::function<void(void*, void*)> _onFocusCallBack;

	UIText				*content;

public:

	UiButtonCircle(std::string Tag, float PosX, float PosY, float Radius,
		int background, int foreground, int border, std::string Text,
		std::function<void(void*, void*)> onClickCallBack);

	UiButtonCircle(std::string Tag, float PosX, float PosY, float Radius,
		int background, int foreground, int border, std::string Text);
	~UiButtonCircle();

	void		InitiazeCompoment();

	void		OnFocus(sf::RenderWindow *window);
	void		OnClick(void *arg = NULL);
	void		OnWindowsSizeChange(float x, float y);
	bool		OnClick(sf::Event *event);
	bool		OnFocus(sf::Event *event);

	void		Draw(sf::RenderWindow *window);
	void		Reset();

	static		UiButtonCircle *NewButton(std::string Tag, float PosX, float PosY, float Radius,
		int background, int foreground, int border, std::string Text,
		std::function<void(void*, void*)> onClickCallBack);

	void		setContent(std::string value);

};

#endif