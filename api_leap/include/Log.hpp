//Log.hpp

#ifndef __LOG_HPP__
#define __LOG_HPP__

#include <iostream>
#include <ctime>



class Log
{

public:
	Log();
	~Log();

	static void info(std::string message);
	static void warning(std::string message); 	
	static void error(std::string message);

	static std::string getTime();
};

#define LOG(text) Log::info(text)
#define WARNING(text) Log::warning(std::string(text)
#define ERROR(text) Log::error(text)

#endif