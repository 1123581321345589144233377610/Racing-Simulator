#include "Race.h"

Race::Race(double distance_, std::string type_) : distance{ distance_ }, type{ type_ } {}

std::string Race::get_type() {
	return type;
}