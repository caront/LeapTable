#ifndef __PROSSE_H__
#define __PROSSE_H__

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

#include "common.hh"

class Prosse
{
private:
	key_t 	_key;
	int 	_shmid;
	
public:
	void 	*shm;
	
public:
	Prosse();
	Prosse(key_t key);
	~Prosse();
	
	void Open();
	void Init();
	void PutData(std::string data);
	std::string GetData();
	void Close();

private:

	void putData(char *obj, const char *data, int size);
};

#endif