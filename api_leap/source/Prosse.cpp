#include "Prosse.hpp"
#include "GetWindowsID.hpp"
#include "Log.hpp"

Prosse::Prosse()
{
	_key = KEYBASE + GetWindowsID();
	shm = NULL;
}


Prosse::Prosse(key_t key)
	: _key(key)
{
	shm = NULL;
}

Prosse::~Prosse(){}

void Prosse::Open(){
	if ((_shmid = shmget(_key, SHMSZ, IPC_CREAT | 0666)) < 0 ){
		ERROR("shmget Open");
	}
}


void Prosse::Init(){
	if (shm == NULL){
		std::cout << (_key) << std::endl;
		if ((_shmid = shmget(_key, SHMSZ, IPC_CREAT | 0666)) < 0 )
			ERROR("shmget Init");
	}
	if ((shm = shmat(_shmid, NULL, 0)) == (char *) -1) {
			ERROR("shmat");
	}
}

void Prosse::PutData(std::string data)
{
	putData((char *)shm, data.c_str(), data.size());
}

std::string Prosse::GetData(){
	return std::string((char *)shm);
}

void Prosse::putData(char *obj, const char *data, int size)
{
	while (size >= 0)
	{
		obj[size] = data[size];
		size--;
	}

}

void Prosse::Close()
{
	if(shmctl(_shmid, IPC_RMID, NULL) < 0)
    {
		std::cerr << "error : shmctl" << std::endl;
    }
}