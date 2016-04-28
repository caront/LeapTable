#ifndef __UIIMAGE_H__
#define __UIIMAGE_H__


#include "UIObject.hpp"
#include "Color.hh"
#include <string>


class UIImage : public UIObject
{
private:
	std::string				_file;
	sf::Texture  			_image;
	sf::Sprite				_sprite;


public:
	UIImage(std::string Tag, float PosX, float PosY, float sizeX, float sizeY, std::string filepath);
	~UIImage();
	
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

	std::string getFile();
	void 		setFile(std::string value);

	static UIImage	*NewImage(std::string Tag, float PosX, float PosY, float sizeX, float sizeY,	std::string file);
};

#endif