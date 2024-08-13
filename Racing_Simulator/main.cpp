#include <iostream>

class Transport {
protected:
	double speed = 0;
};

class LandTransport : public Transport {
protected:
	double speed = 0;
	double driving_time_before_rest = 0;
	double duration_of_rest1 = 0;
	double duration_of_rest2 = 0;
	double duration_of_rest3 = 0;
	LandTransport(double speed_, double driving_time_before_rest_, double duration_of_rest1_, double duration_of_rest2_, double duration_of_rest3_) : speed{speed_}, driving_time_before_rest{driving_time_before_rest_}, duration_of_rest1{duration_of_rest1_}, duration_of_rest2{ duration_of_rest2_ }, duration_of_rest3{ duration_of_rest3_ } {}
};


class Camel : public LandTransport {
public:
	Camel() : LandTransport(10, 30, 5, 8, 8) {}
};

class FastCamel : public LandTransport {
public:
	FastCamel() : LandTransport(40, 10, 5, 6.5, 8) {}
};

class Centaur : LandTransport {
public:
	Centaur() : LandTransport(15, 8, 2, 2, 2) {}
};

class Boots : public LandTransport {
public:
	Boots() : LandTransport(6, 60, 10, 5, 5) {}
};

class AirTransport : public Transport {
private:

};

int main() {
	return 0;
}