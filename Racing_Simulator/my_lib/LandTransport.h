#pragma once
#include "Transport.h"
#ifndef MY_LIBRARY 
#define MY_LIB_API __declspec(dllexport)
#else
#define MY_LIB_API __declspec(dllimport)
#endif

class LandTransport : public Transport {
private:
	double speed = 0;
	double driving_time_before_rest = 0;
	double duration_of_rest1 = 0;
	double duration_of_rest2 = 0;
	double duration_of_rest3 = 0;
	std::string type;
	int count = 0;
protected:
	MY_LIB_API LandTransport(double speed_, double driving_time_before_rest_, double duration_of_rest1_, double duration_of_rest2_, double duration_of_rest3_, std::string type_);
public:
	MY_LIB_API std::string get_type();
	MY_LIB_API void set_count(int x);
	MY_LIB_API int get_count();
	MY_LIB_API double calc_time(double distance);
};