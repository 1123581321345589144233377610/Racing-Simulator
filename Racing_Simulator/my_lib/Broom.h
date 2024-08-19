#pragma once
#include "AirTransport.h"
#ifndef MY_LIBRARY 
#define MY_LIB_API __declspec(dllexport)
#else
#define MY_LIB_API __declspec(dllimport)
#endif

class Broom : public AirTransport {
public:
	MY_LIB_API Broom();
	double calc_time(double distance) override {
		return distance * (1 - ((floor(distance / 1000)) / (100))) / (Broom().get_speed());
	}
};