#pragma once
#include "Transport.h"
#ifndef MY_LIBRARY 
#define MY_LIB_API __declspec(dllexport)
#else
#define MY_LIB_API __declspec(dllimport)
#endif

class AirTransport : public Transport {
private:
	double speed = 0;
	double coeff = 0;
	std::string type;
	int count = 0;
protected:
	MY_LIB_API AirTransport(double speed_, std::string type_);
	MY_LIB_API AirTransport(double speed_, std::string type_, double coeff_);
public:
	MY_LIB_API std::string get_type();
	MY_LIB_API void set_count(int x);
	MY_LIB_API int get_count();
	MY_LIB_API double get_coeff();
	MY_LIB_API void set_coeff(double coeff_);
	MY_LIB_API double get_speed();
	MY_LIB_API virtual double calc_time(double distance) {
		return 0;
	};
};