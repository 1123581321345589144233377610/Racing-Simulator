#pragma once
#include <string>
#ifndef MY_LIBRARY 
#define MY_LIB_API __declspec(dllexport)
#else
#define MY_LIB_API __declspec(dllimport)
#endif

class Race {
private:
	double distance = 0;
	std::string type;
protected:
	MY_LIB_API Race(double distance_, std::string type_);
public:
	MY_LIB_API std::string get_type();
};