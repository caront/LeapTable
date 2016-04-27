#include "PageConstructor.hpp"


PageConstructor::PageConstructor()
{
}


PageConstructor::~PageConstructor()
{
}
 
Page *Constuction(std::string filePath)
{
	return new Page();
}
