#include "WindowXMlReader.hpp"

int GetIntFromHexaString(std::string str)
{
	std::stringstream ss;
	unsigned int i;

	ss << std::hex << str.c_str();
	ss >> i;
	return i;
}


WindowXMlReader::WindowXMlReader(std::string rootPath)
	: _rootPath(rootPath)
{
	LOG("rootPath : " + rootPath);
}


WindowXMlReader::~WindowXMlReader()
{
}


void				WindowXMlReader::Init()
{
	if (!OpenDoc(&_Rootdoc, _rootPath + "/Window.xml"))
		return;
	tinyxml2::XMLElement *elementRoot;
	elementRoot = _Rootdoc.FirstChildElement("Window");
	tinyxml2::XMLElement *element = elementRoot->FirstChildElement("Page");
	for (tinyxml2::XMLElement *element = elementRoot->FirstChildElement("Page");
		element != NULL;
		element = element->NextSiblingElement())
	{
		_PageListFiles[element->Attribute("Tag")] = element->Attribute("File");
	}
	it = _PageListFiles.begin();
}

std::string			WindowXMlReader::NextPage()
{
	if (it == _PageListFiles.end())
		return "";
	std::string	ret = ((*it).second);
	it++;
	return ret;
}

Page				*WindowXMlReader::ReadPageDoc(std::string fileName, CollectionElement *collectionElement){
	Page *ret = new Page();
	tinyxml2::XMLElement *elementRoot;
	tinyxml2::XMLDocument Pagedoc;
	std::string fp = _rootPath + "/Pages/" + fileName;
	LOG(fp);
	std::cout << fp << std::endl;
	if (!OpenDoc(&Pagedoc, fp))
	{
		ERROR("Can't OpenDoc" + fileName);
		return NULL;
	}
	elementRoot = Pagedoc.FirstChildElement("Page");
	ret->setTag(elementRoot->Attribute("Tag"));
	ret->setBackground(GetIntFromHexaString(std::string(elementRoot->Attribute("Background"))));
	for (tinyxml2::XMLElement *element = elementRoot->FirstChildElement("Object");
		element != NULL;
		element = element->NextSiblingElement())
	{
		if (std::string(element->Attribute("Type")) == "Button")
			ret->AddElement(this->GetButton(element, collectionElement));
		if (std::string(element->Attribute("Type")) == "CurcularButton")
			ret->AddElement(this->GetButtonCircle(element, collectionElement));
		if (std::string(element->Attribute("Type")) == "TextBlock")
			ret->AddElement(this->GetText(element));
		if (std::string(element->Attribute("Type")) == "Image")
			ret->AddElement(this->GetImage(element));
		if (std::string(element->Attribute("Type")) == "Rendu")
			ret->AddElement(this->GetImage(element));		
	}
	return ret;
}

UIButton		*WindowXMlReader::GetButton(tinyxml2::XMLElement *buttonInfoXMl, CollectionElement *collectionElement)
{
	UIButton *ret = UIButton::NewButton(buttonInfoXMl->Attribute("Tag"),
		static_cast<float>(atof(buttonInfoXMl->Attribute("Posx"))),
		static_cast<float>(atof(buttonInfoXMl->Attribute("Posy"))),
		static_cast<float>(atof(buttonInfoXMl->Attribute("Height"))),
		static_cast<float>(atof(buttonInfoXMl->Attribute("Width"))),
		GetIntFromHexaString(std::string(buttonInfoXMl->Attribute("Background"))),
		GetIntFromHexaString(std::string(buttonInfoXMl->Attribute("Foreground"))),
		GetIntFromHexaString(std::string(buttonInfoXMl->Attribute("Border"))),
		buttonInfoXMl->Attribute("ContentText"),
		collectionElement->callbackListener->GetFunctionByTag(buttonInfoXMl->Attribute("OnClick")));
	return ret;
}

UiButtonCircle		*WindowXMlReader::GetButtonCircle(tinyxml2::XMLElement *buttonInfoXMl, CollectionElement *collectionElement)
{
	UiButtonCircle *ret = UiButtonCircle::NewButton(buttonInfoXMl->Attribute("Tag"),
		static_cast<float>(atof(buttonInfoXMl->Attribute("Posx"))),
		static_cast<float>(atof(buttonInfoXMl->Attribute("Posy"))),
		static_cast<float>(atof(buttonInfoXMl->Attribute("Radius"))),
		GetIntFromHexaString(std::string(buttonInfoXMl->Attribute("Background"))),
		GetIntFromHexaString(std::string(buttonInfoXMl->Attribute("Foreground"))),
		GetIntFromHexaString(std::string(buttonInfoXMl->Attribute("Border"))),
		buttonInfoXMl->Attribute("ContentText"),
		collectionElement->callbackListener->GetFunctionByTag(buttonInfoXMl->Attribute("OnClick")));
	return ret;
}

UIText			*WindowXMlReader::GetText(tinyxml2::XMLElement *textInfoXML)
{
	sf::Font *font = new sf::Font();
	const std::string fontpath = "./window/Assets/Fonts/Aaargh.ttf";
	if (!font->loadFromFile(fontpath))
	{
		//std::cout << font->getInfo().family << std::endl;
		getchar();
	}

	return UIText::NewText(textInfoXML->Attribute("Tag"),
		static_cast<float>(atof(textInfoXML->Attribute("Posx"))),
		static_cast<float>(atof(textInfoXML->Attribute("Posy"))),
		textInfoXML->Attribute("Text"),
		font,
		atoi(textInfoXML->Attribute("TextSize")),
		GetIntFromHexaString(std::string(textInfoXML->Attribute("Foreground"))));

}

bool  WindowXMlReader::OpenDoc(tinyxml2::XMLDocument *doc, std::string filePath)
{
	LOG(filePath.c_str());
	if (doc->LoadFile(filePath.c_str()))
	{
		ERROR("OpenDoc : " + std::string(doc->GetErrorStr1()));
		return false;
	}
	return true;
}

UIMenu *WindowXMlReader::ReadMenuDoc(CollectionElement *collectionElement)
{
	UIMenu *ret = new UIMenu();
	tinyxml2::XMLElement *elementRoot;
	tinyxml2::XMLDocument Pagedoc;
	std::string fp = _rootPath + "/Menu/menu.xml" ;
	std::cout << fp << std::endl;
	if (!OpenDoc(&Pagedoc, fp))
		return NULL;
	elementRoot = Pagedoc.FirstChildElement("Menu");
	ret->setColor(GetIntFromHexaString(std::string(elementRoot->Attribute("Color"))));
	for (tinyxml2::XMLElement *element = elementRoot->FirstChildElement("Element");
		element != NULL;
		element = element->NextSiblingElement())
	{
		ret->addElement(GetMenuElement(element, collectionElement));
	}
	return ret;
}

UIMenuElement 		*WindowXMlReader::GetMenuElement(tinyxml2::XMLElement *element, CollectionElement *collectionElement)
{
	return new UIMenuElement(element->Attribute("Pos"),
		element->Attribute("Text"),
		collectionElement->callbackListener->GetFunctionByTag(element->Attribute("Callback")),
		GetIntFromHexaString(std::string(element->Attribute("Color"))),
		GetIntFromHexaString(std::string(element->Attribute("Forground"))));
}

UIImage 			*WindowXMlReader::GetImage(tinyxml2::XMLElement *element)
{
	return UIImage::NewImage(element->Attribute("Tag"),
		static_cast<float>(atof(element->Attribute("Posx"))),
		static_cast<float>(atof(element->Attribute("Posy"))),
		static_cast<float>(atof(element->Attribute("Sizex"))),
		static_cast<float>(atof(element->Attribute("Sizey"))),
		_rootPath + "/Assets/Textures/" + element->Attribute("Source"));
}


UIImage 			*WindowXMlReader::GetModel(tinyxml2::XMLElement *element)
{
	return UIImage::NewImage(element->Attribute("Tag"),
		static_cast<float>(atof(element->Attribute("Posx"))),
		static_cast<float>(atof(element->Attribute("Posy"))),
		static_cast<float>(atof(element->Attribute("Sizex"))),
		static_cast<float>(atof(element->Attribute("Sizey"))),
		_rootPath + "/Assets/3DModels/" + element->Attribute("Source"));
}
