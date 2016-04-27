#ifndef __SHARED_MEMORY_H__
#define __SHARED_MEMORY_H__ 

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "Log.hpp"

class SharedMemory
{
private:
	int 		shmid;
    key_t 		key;
    void 		*shm;
    char 		*s;

public:
	SharedMemory();
	~SharedMemory();


	
};

#endif