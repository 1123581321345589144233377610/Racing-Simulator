#pragma once
#include "LandTransport.h"
#ifndef MY_LIBRARY 
#define MY_LIB_API __declspec(dllexport)
#else
#define MY_LIB_API __declspec(dllimport)
#endif

class Centaur : public LandTransport {
public:
	MY_LIB_API Centaur();
};
