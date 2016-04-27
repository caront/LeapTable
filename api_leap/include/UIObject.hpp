//IButton.hpp

#ifndef __UIOBJECT_H__
#define __UIOBJECT_H__


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class UIObject
{
protected:

	float					_posX;
	float					_posY;

	float					_height;
	float					_width;
	std::string			_tag;
	bool				_isFocus;
	bool				_isClick;
	int					_scaleFocus;
	bool				_UIPropChanged;
public:
	UIObject();
	UIObject(std::string Tag, float PosX, float PosY, float Height, float width);
	~UIObject();


	float	getPosX() const;
	float	getPosY() const;
	float	getHeight() const;
	float	getWidth() const;
	
	void	setPosX(float value);
	void	setPosY(float value);
	void	setHeight(float value);
	void	setWitdh(float value);

	std::string getTag() const;

	virtual void Reset() = 0;
	virtual void OnWindowsSizeChange(float x, float y) = 0;
	virtual void Draw(sf::RenderWindow *windows) = 0;

	virtual void OnClick(void *arg = NULL) = 0;
	virtual void OnFocus(sf::RenderWindow *window) = 0;

	virtual bool OnClick(sf::Event *event) = 0;
	virtual bool OnFocus(sf::Event *event) = 0;
};

#endif