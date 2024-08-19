#include "LandTransport.h"

LandTransport::LandTransport(double speed_, double driving_time_before_rest_, double duration_of_rest1_, double duration_of_rest2_, double duration_of_rest3_, std::string type_) : speed{ speed_ }, driving_time_before_rest{ driving_time_before_rest_ }, duration_of_rest1{ duration_of_rest1_ }, duration_of_rest2{ duration_of_rest2_ }, duration_of_rest3{ duration_of_rest3_ }, type{ type_ } {}

std::string LandTransport::get_type(){
	return type;
}

void LandTransport::set_count(int x) {
	this->count = x;
}

int LandTransport::get_count() {
	return count;
}

double LandTransport::calc_time(double distance) {
	double time{ distance / speed };
	int number_of_rests{ static_cast<int>(floor(time / driving_time_before_rest)) };
	if (number_of_rests > 0) {
		time += duration_of_rest1;
		--number_of_rests;
	}
	if (number_of_rests > 0) {
		time += duration_of_rest2;
		--number_of_rests;
	}
	while (number_of_rests > 0) {
		time += duration_of_rest3;
		--number_of_rests;
	}
	return time;
}


