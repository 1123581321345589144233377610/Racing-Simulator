#include "AirTransport.h"

AirTransport::AirTransport(double speed_, std::string type_) : speed{ speed_ }, type{ type_ } {}

AirTransport::AirTransport(double speed_, std::string type_, double coeff_) : speed{ speed_ }, type{ type_ }, coeff { coeff_ } {}

std::string AirTransport::get_type() {
	return type;
}

void AirTransport::set_count(int x) {
	this->count = x;
}

int AirTransport::get_count() {
	return count;
}

double AirTransport::get_coeff() {
	return coeff;
}

void AirTransport::set_coeff(double coeff_) {
	this->coeff = coeff_;
}

double AirTransport::get_speed() {
	return speed;
}
