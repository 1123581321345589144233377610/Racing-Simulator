#pragma once
#include "Race.h"
#ifndef MY_LIBRARY 
#define MY_LIB_API __declspec(dllexport)
#else
#define MY_LIB_API __declspec(dllimport)
#endif

class LandAirRace : public Race {
public:
	MY_LIB_API LandAirRace(double distance_);
};