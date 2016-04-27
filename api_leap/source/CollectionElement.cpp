#include "CollectionElement.hpp"

#include "Log.hpp"
CollectionElement::CollectionElement(std::string CollectionFolderPath)
	: _collectionFolderPath(CollectionFolderPath)
{
	_reader = new WindowXMlReader(CollectionFolderPath);
	callbackListener = new CallBackListener();
}


CollectionElement::~CollectionElement()
{
}

void			CollectionElement::InitCollection()
{
	callbackListener->Init();
	_reader->Init();
	this->InitPageCollection();
}



void		CollectionElement::InitPageCollection()
{
	std::string pageFilePath;
	Page		*tmp;
	while ((pageFilePath = _reader->NextPage()) != "")
	{
		tmp = _reader->ReadPageDoc(pageFilePath, this);
		if (tmp != NULL)
		{
			LOG("NEW PAGE " + tmp->getTag());
			_pages[tmp->getTag()] = tmp;
		}
	}
}

void		CollectionElement::InitTextureCollection()
{

}

void		CollectionElement::InitCallbackCollection()
{

}

void		CollectionElement::InitFontCollection()
{

}

Page		*CollectionElement::getPageByTag(std::string tag)
{
	return _pages[tag];
}

UIObject	*CollectionElement::getObjectByTag(std::string tag)
{
	UIObject	*obj = NULL;
	for (std::map<std::string, Page *>::iterator it = _pages.begin(); it != _pages.end(); it++)
	{
		if ((obj = (*it).second->GetObjectList()->GetObjectByTag(tag)) != NULL)
			return obj;
	}
	return NULL;
}

Page		*CollectionElement::getMainPage()
{
	return (*_pages.begin()).second;
}