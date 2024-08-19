#pragma once
#include "Race.h"
#ifndef MY_LIBRARY 
#define MY_LIB_API __declspec(dllexport)
#else
#define MY_LIB_API __declspec(dllimport)
#endif

class LandRace : public Race{
public:
	MY_LIB_API LandRace(double distance_);
};