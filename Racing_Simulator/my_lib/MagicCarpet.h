#pragma once
#include "AirTransport.h"
#ifndef MY_LIBRARY 
#define MY_LIB_API __declspec(dllexport)
#else
#define MY_LIB_API __declspec(dllimport)
#endif


class MagicCarpet : public AirTransport {
public:
	MY_LIB_API MagicCarpet();
	MY_LIB_API double calc_time(double distance) override {
		double coeff;
		if (distance < 1000) coeff = 0;
		else if (distance < 5000) coeff = 3;
		else if (distance < 10000) coeff = 10;
		else coeff = 5;
		return distance * (1 - ((coeff) / 100)) / (MagicCarpet().get_speed());
	}
};