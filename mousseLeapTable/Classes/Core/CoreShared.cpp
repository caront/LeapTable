#include "CoreShared.hpp"

#include "GetWindowsID.hpp"
CoreShared::CoreShared(){}
CoreShared::~CoreShared(){}

void 	CoreShared::OpenShm(int id)
{
	prossemap[id]->Init();
}


void 	CoreShared::CloseShm(int id)
{
	prossemap[id]->Close();
}

void 	CoreShared::SendData(int id, std::string data)
{
	prossemap[id]->PutData(data);
}

std::string CoreShared::GetData(int id)
{
	return prossemap[id]->GetData();
}

void CoreShared::Init(int id)
{
	prossemap[id] = new Prosse(KEYBASE + id);
}

void CoreShared::SendToFocused(std::string data)
{
	int id = GetWindowsID();
	std::cout << id << std::endl;
	if (!isInMap(id))
	{
		this->Init(id);
		this->OpenShm(id);
	}
	this->SendData(id, data);
}

bool CoreShared::isInMap(int id)
{
	std::map<int ,Prosse *>::const_iterator it = prossemap.find(id);
	return it != prossemap.end();
}