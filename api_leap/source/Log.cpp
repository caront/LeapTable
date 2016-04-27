//Log.cpp

#include "Log.hpp"

Log::Log(){}
Log::~Log(){}

std::string Log::getTime(){
	time_t rawtime;
  	struct tm * timeinfo;
  	char buffer[80];

  	time (&rawtime);
  	timeinfo = localtime(&rawtime);

  	strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeinfo);
  	std::string str(buffer);
  	return str;
}

void Log::info(std::string message){
	std::cout << "[" << Log::getTime() << "][Info]" << message << std::endl;
}


void Log::warning(std::string message){
	std::cout << "[" << Log::getTime() << "][Warning]" << message << std::endl;
}


void Log::error(std::string message){
	std::cerr << "[" << Log::getTime() << "][Error]" << message << std::endl;
}
