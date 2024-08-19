#include <iostream>
#include <cmath>
#include <vector>
#include <Windows.h>
#include "Transport.h"
#include "LandTransport.h"
#include "Camel.h"
#include "FastCamel.h"
#include "Centaur.h"
#include "Boots.h"
#include "AirTransport.h"
#include "MagicCarpet.h"
#include "Eagle.h"
#include "Broom.h"
#include "Race.h"
#include "LandRace.h"
#include "AirRace.h"
#include "LandAirRace.h"

int main() {
	LandRace LR(0); 
	AirRace AR(0); 
	LandAirRace LAR(0); 
	int type{}; 
	double distance{}; 
	int tmp{}, count{};
	Boots B; Broom BR; Camel C; Centaur CT; Eagle E; FastCamel FC; MagicCarpet MC;
	std::vector<std::pair<std::string, double>> res;
	std::cout << "Welcome to the racing simulator!" << std::endl;
	while (true) {
		std::string reg_transport{"Registered vehicles: "};
		std::cout << "1. " << LR.get_type() << std::endl;
		std::cout << "2. " << AR.get_type() << std::endl;
		std::cout << "3. " << LAR.get_type() << std::endl;
		std::cout << "Choose the type of race: ";
		std::cin >> type;
		while (true) {
			if (type >= 1 && type <= 3) break;
			else {
				std::cout << "Trying to choose the wrong type of race!" << std::endl;
				std::cout << "Choose the type of race: ";
				std::cin >> type;
			}
		}
		std::cout << "Specify the distance length (must be positive): ";
		std::cin >> distance;
		while (true) {
			if (distance > 0) break;
			else {
				std::cout << "An attempt to indicate a negative distance!" << std::endl;
				std::cout << "Specify the distance length (must be positive): ";
				std::cin >> distance;
			}
		}
		std::cout << "At least 2 vehicles must be registered" << std::endl;
		std::cout << "1. Register a transport" << std::endl;
		std::cout << "Select an action: ";
		std::cin >> tmp;
		while (true) {
			if (tmp == 1) break;
			else {
				std::cout << "An attempt to select a non-existent action!" << std::endl;
				std::cout << "Select an action: ";
				std::cin >> tmp;
			}
		}
		while (true) {
			switch (type) {
			case 1: std::cout << LR.get_type() << ". Distance: " << distance << std::endl; break;
			case 2: std::cout << AR.get_type() << ". Distance: " << distance << std::endl; break;
			default: std::cout << LAR.get_type() << ". Distance: " << distance << std::endl; break;
			}
			if (count >= 1) std::cout << reg_transport << std::endl;
			std::cout << "1. " << "Boots" << std::endl;
			std::cout << "2. " << "Broom" << std::endl;
			std::cout << "3. " << "Camel" << std::endl;
			std::cout << "4. " << "Centaur" << std::endl;
			std::cout << "5. " << "Eagle" << std::endl;
			std::cout << "6. " << "Fast Camel" << std::endl;
			std::cout << "7. " << "Magic Carpet" << std::endl;
			std::cout << "0. " << "Finish the registration" << std::endl;
			std::cout << "Select transport or 0 to end the registration process: ";
			std::cin >> tmp;
			if (tmp == 0 && count >= 2) {
				std::cout << "1. Register a transport" << std::endl;
				std::cout << "2. Start the race" << std::endl;
				std::cout << "Select an action: ";
				std::cin >> tmp;
				while (true) {
					if (tmp == 1 || tmp == 2) break;
					else {
						std::cout << "An attempt to select a non-existent action!" << std::endl;
						std::cout << "Select an action: ";
						std::cin >> tmp;
					}
				}
				if (tmp == 1) continue;
				else if (tmp == 2) break;
			}
			while (true) {
				if (tmp >= 1 && tmp <= 7) {
					++count;
					break;
				}
				else if (tmp == 0 && count < 2) {
					std::cout << "At least 2 vehicles must be registered!" << std::endl;
					std::cout << "Select transport or 0 to end the registration process: ";
					std::cin >> tmp;
					continue;
				}
				else {
					std::cout << "An attempt to select a non-existent action!" << std::endl;
					std::cout << "Select transport or 0 to end the registration process: ";
					std::cin >> tmp;
				}
			}
			if (type == 1 && (tmp == 7 || tmp == 5 || tmp == 2)) {
				--count;
				std::cout << "Attempt to register the wrong type of vehicle!" << std::endl;
				continue;
			}
			else if (type == 2 && (tmp == 3 || tmp == 6 || tmp == 4 || tmp == 1)) {
				--count;
				std::cout << "Attempt to register the wrong type of vehicle!" << std::endl;
				continue;
			}
			switch (tmp) {
			case 1: 
				  B.set_count((B.get_count()) + 1);
				  if (B.get_count() > 1) {
					  std::cout << B.get_type() << " already registered!" << std::endl;
					  B.set_count(B.get_count() - 1);
					  break;
				  }
				  std::cout << B.get_type() << " successfully registered!" << std::endl;
				  reg_transport += (count == 1) ? B.get_type() : ", " + B.get_type();
				  break;
			case 2:
				BR.set_count((BR.get_count()) + 1);
				if (BR.get_count() > 1) {
					std::cout << BR.get_type() << " already registered!" << std::endl;
					BR.set_count(BR.get_count() - 1);
					break;
				}
				std::cout << BR.get_type() << " successfully registered!" << std::endl;
				reg_transport += (count == 1) ? BR.get_type() : ", " + BR.get_type();
				break;
			case 3:
				C.set_count((C.get_count()) + 1);
				if (C.get_count() > 1) {
					std::cout << C.get_type() << " already registered!" << std::endl;
					C.set_count(C.get_count() - 1);
					break;
				}
				std::cout << C.get_type() << " successfully registered!" << std::endl;
				reg_transport += (count == 1) ? C.get_type() : ", " + C.get_type();
				break;
			case 4:
				CT.set_count((CT.get_count()) + 1);
				if (CT.get_count() > 1) {
					std::cout << CT.get_type() << " already registered!" << std::endl;
					CT.set_count(CT.get_count() - 1);
					break;
				}
				std::cout << CT.get_type() << " successfully registered!" << std::endl;
				reg_transport += (count == 1) ? CT.get_type() : ", " + CT.get_type();
				break;
			case 5:
				E.set_count((E.get_count()) + 1);
				if (E.get_count() > 1) {
					std::cout << E.get_type() << " already registered!" << std::endl;
					E.set_count(E.get_count() - 1);
					break;
				}
				std::cout << E.get_type() << " successfully registered!" << std::endl;
				reg_transport += (count == 1) ? E.get_type() : ", " + E.get_type();
				break;
			case 6:
				FC.set_count((FC.get_count()) + 1);
				if (FC.get_count() > 1) {
					std::cout << FC.get_type() << " already registered!" << std::endl;
					FC.set_count(FC.get_count() - 1);
					break;
				}
				std::cout << FC.get_type() << " successfully registered!" << std::endl;
				reg_transport += (count == 1) ? FC.get_type() : ", " + FC.get_type();
				break;
			case 7:
				MC.set_count((MC.get_count()) + 1);
				if (MC.get_count() > 1) {
					std::cout << MC.get_type() << " already registered!" << std::endl;
					MC.set_count(MC.get_count() - 1);
					break;
				}
				std::cout << MC.get_type() << " successfully registered!" << std::endl;
				reg_transport += (count == 1) ? MC.get_type() : ", " + MC.get_type();
				break;
			}
			continue;
		}
		if (B.get_count() == 1) {
			res.push_back({ B.get_type(), B.calc_time(distance)});
		}
		if (BR.get_count() == 1) {
			res.push_back({ BR.get_type(), BR.calc_time(distance) });
		}
		if (C.get_count() == 1) {
			res.push_back({ C.get_type(), C.calc_time(distance) });
		}
		if (CT.get_count() == 1) {
			res.push_back({ CT.get_type(), CT.calc_time(distance) });
		}
		if (E.get_count() == 1) {
			res.push_back({ E.get_type(), E.calc_time(distance) });
		}
		if (FC.get_count() == 1) {
			res.push_back({ FC.get_type(), FC.calc_time(distance) });
		}
		if (MC.get_count() == 1) {
			res.push_back({ MC.get_type(), MC.calc_time(distance) });
		}
		for (size_t i{}; i < res.size(); ++i) {
			for (size_t j{}; j < res.size() - 1; ++j) {
				if (res[j].second > res[j + 1].second) {
					std::swap(res[j], res[j + 1]);
				}
			}
		}
		std::cout << "Race results:" << std::endl;
		for (size_t i{}; i < res.size(); ++i) {
			std::cout << i + 1 << ". " << res[i].first << ". Time: " << res[i].second << std::endl;
		}
		std::cout << std::endl;
		std::cout << "1. To hold another race" << std::endl;
		std::cout << "2. Exit" << std::endl;
		std::cout << "Select an action: ";
		std::cin >> tmp;
		while (true) {
			if (tmp == 1 || tmp == 2) break;
			else {
				std::cout << "An attempt to select a non-existent action!" << std::endl;
				std::cout << "Select an action: ";
				std::cin >> tmp;
			}
		}
		if (tmp == 1) {
			B.set_count(0);
			BR.set_count(0);
			C.set_count(0);
			CT.set_count(0);
			E.set_count(0);
			FC.set_count(0);
			MC.set_count(0);
			count = 0;
			res.clear();
			continue;
		}
		else if (tmp == 2) break;
	}
	return EXIT_SUCCESS;
}

