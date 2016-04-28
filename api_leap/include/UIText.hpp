#ifndef __UITEXT_H__
#define __UITEXT_H__

#include "UIObject.hpp"
#include "Color.hh"
#include <string>

class UIText : public UIObject
{
private:
	std::string				_text;
	int						_textSize;
	sf::Font				*_font;
	sf::Text				*_textShape;
	Color					_foreground;

public:
	UIText(std::string Tag, float PosX, float PosY,
		std::string text, sf::Font *font, int textSize, int forground);
	~UIText();

	void		InitiazeCompoment();
	void		OnFocus(sf::RenderWindow *window) {}
	void		OnClick(void *arg = NULL) {}

	void		OnWindowsSizeChange(float x, float y);
	bool		OnClick(sf::Event *event){
		return false;
	};
	bool		OnFocus(sf::Event *event){
		return false;
	};

	void		Draw(sf::RenderWindow *window);
	void		Reset();

	void		setText(const std::string value);
	void		setTextSize(int value);
	void		setTextFont(sf::Font *value);
	void		setForground(int value);
	void		setForground(Color value);

	std::string	getText() const;
	int			getTextSize() const;
	sf::Font	getTextFont() const;
	Color		getForground() const;

	void		originInMidle();
	void 		setOrigin(float x, float y);

	static UIText	*NewText(std::string Tag, float PosX, float PosY,
		std::string text, sf::Font *font, int textSize, int forground);

};

#endif