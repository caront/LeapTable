#ifndef __WINDOW_XML_READER_H__
#define __WINDOW_XML_READER_H__


#include <tinyxml2.h>
#include "Page.hpp"
#include "CallBackListener.hpp"
#include <string>
#include <sstream>
#include "CollectionElement.hpp"
#include "UIButtonCircle.hpp"
#include "Log.hpp"


class CollectionElement;
class Page;

class WindowXMlReader
{
	tinyxml2::XMLDocument			_Rootdoc;
	tinyxml2::XMLDocument			_Pagedoc;
	tinyxml2::XMLDocument			_Textdoc;
	std::string						_rootPath;
	std::map<std::string, std::string > _PageListFiles;
	std::map<std::string, std::string >::iterator it;
	

public:
	WindowXMlReader(std::string rootPath);
	~WindowXMlReader();


	void				Init();

	std::string			NextPage();

	Page				*ReadPageDoc(std::string fileName, CollectionElement *collectionElement);



	UIButton			*GetButton(tinyxml2::XMLElement *element, CollectionElement *collectionElement);
	UiButtonCircle		*GetButtonCircle(tinyxml2::XMLElement *element, CollectionElement *collectionElement);
	UIText				*GetText(tinyxml2::XMLElement *element);
	static bool			OpenDoc(tinyxml2::XMLDocument *doc, std::string filePath);
};

#endif