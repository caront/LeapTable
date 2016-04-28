#include "Prosse.hpp"

Prosse::Prosse()
{
	_key = KEYBASE + getpid();
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
		std::cerr << "error : shmget" << std::endl;
	}
}


void Prosse::Init(){
	if (shm == NULL){
	if ((_shmid = shmget(_key, SHMSZ, IPC_CREAT | 0666)) < 0 )
		std::cerr << "error : shmget" << std::endl;
	}
	if ((shm = shmat(_shmid, NULL, 0)) == (char *) -1) {
		std::cerr << "error : shmat" << std::endl;
	}
}

void Prosse::PutData(std::string data)
{
	putData((char *)shm, data.c_str(), data.size());
	std::cout << (char *)shm << std::endl;
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