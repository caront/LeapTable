#ifndef __CORE_SHARED_H__
#define __CORE_SHARED_H__ 

#include "common.hh"
#include "Prosse.hpp"
#include <map>

class CoreShared
{
private:
	std::map<int, Prosse *> prossemap;

public:
	CoreShared();
	~CoreShared();
	
	void 	OpenShm(int id);
	void 	SendData(int id, std::string data);
	std::string GetData(int id);
	void 	CloseShm(int id);

	void Init(int id);

	void SendToFocused(std::string data);

private:

	bool isInMap(int id);
};

#endif