#ifndef __COLLECTIONELEMENT_H__
#define __COLLECTIONELEMENT_H__

#include <string>
#include <map>
#include "Page.hpp"
#include "UIMenu.hpp"
class WindowXMlReader;
class Page;

class CollectionElement
{
public:
	CallBackListener				*callbackListener;

private:
	std::map<std::string, Page *>		_pages;
	std::map<std::string, sf::Font *>	_fonts;

	WindowXMlReader					*_reader;
	std::string						_collectionFolderPath;

public:
	CollectionElement(std::string CollectionFolderPath,
	 CallBackListener *callBackListener);
	~CollectionElement();

	void		InitCollection();

	UIObject	*getObjectByTag(std::string tag);
//	UIObject	*getTextureByTag(std::string tag);
	UIObject	*getCallbackByTag(std::string tag);
	sf::Font	*getfontByTag(std::string tag);

	UIMenu		*getMenu();

	Page		*getPageByTag(std::string tag);
	Page		*getMainPage();
private:

	void		InitPageCollection();
	void		InitTextureCollection();
	void		InitCallbackCollection();
	void		InitFontCollection();
};

#endif