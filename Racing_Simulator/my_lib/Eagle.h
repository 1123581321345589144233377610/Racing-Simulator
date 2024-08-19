#pragma once
#include "AirTransport.h"
#ifndef MY_LIBRARY 
#define MY_LIB_API __declspec(dllexport)
#else
#define MY_LIB_API __declspec(dllimport)
#endif

class Eagle : public AirTransport {
public:
	MY_LIB_API Eagle();
	double calc_time(double distance) override{
		return distance * (1 - (Eagle().get_coeff()) / 100) / (Eagle().get_speed());
	}
};