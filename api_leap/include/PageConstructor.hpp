#ifndef __PAGE_CONSTRUCTOR_H__
#define __PAGE_CONSTRUCTOR_H__


#include "Page.hpp"

class PageConstructor
{
public:
	PageConstructor();
	~PageConstructor();

	Page *Constuction(std::string file);
};

#endif