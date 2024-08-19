#pragma once
#include "Race.h"
#ifndef MY_LIBRARY 
#define MY_LIB_API __declspec(dllexport)
#else
#define MY_LIB_API __declspec(dllimport)
#endif

class AirRace : public Race {
public:
	MY_LIB_API AirRace(double distance_);
};
