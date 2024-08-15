#include <iostream>
#include <cmath>
#include <vector>
#include <Windows.h>

class Transport {
private:
};

class LandTransport : public Transport {
private:
	double speed = 0;
	double driving_time_before_rest = 0;
	double duration_of_rest1 = 0;
	double duration_of_rest2 = 0;
	double duration_of_rest3 = 0;
	std::string type;
	int count = 0;
protected:
	LandTransport(double speed_, double driving_time_before_rest_, double duration_of_rest1_, double duration_of_rest2_, double duration_of_rest3_, std::string type_) : speed{ speed_ }, driving_time_before_rest{ driving_time_before_rest_ }, duration_of_rest1{ duration_of_rest1_ }, duration_of_rest2{ duration_of_rest2_ }, duration_of_rest3{ duration_of_rest3_ }, type{ type_ } {}
public:
	std::string get_type(){
		return type;
	}
	void set_count(int x) {
		this->count = x;
	}
	int get_count() {
		return count;
	}
	double calc_time(double distance) {
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
};


class Camel : public LandTransport {
public:
	Camel() : LandTransport(10, 30, 5, 8, 8, "Верблюд") {}
};

class FastCamel : public LandTransport {
public:
	FastCamel() : LandTransport(40, 10, 5, 6.5, 8, "Верблюд-быстроход") {}
};

class Centaur : public LandTransport {
public:
	Centaur() : LandTransport(15, 8, 2, 2, 2, "Кентавр") {}
};

class Boots : public LandTransport {
public:
	Boots() : LandTransport(6, 60, 10, 5, 5, "Ботинки-вездеходы") {}
};

class AirTransport : public Transport {
private:
	double speed = 0;
	double coeff = 0;
	std::string type;
	int count = 0;
protected:
	AirTransport(double speed_, std::string type_) : speed{ speed_ }, type{ type_ } {}
	AirTransport(double speed_, std::string type_, double coeff_) : speed{ speed_ }, type{ type_ }, coeff { coeff_ } {}
public:
	std::string get_type() {
		return type;
	}
	void set_count(int x) {
		this->count = x;
	}
	int get_count() {
		return count;
	}
	double get_coeff() {
		return coeff;
	}
	void set_coeff(double coeff_) {
		this->coeff = coeff_;
	}
	double get_speed() {
		return speed;
	}
	virtual double calc_time(double distance) {
		return 0;
	};
};

class MagicCarpet : public AirTransport {
public:
	MagicCarpet() : AirTransport(10, "Ковёр-самолёт") {}
	double calc_time(double distance) override {
		double coeff;
		if (distance < 1000) coeff = 0;
		else if (distance < 5000) coeff = 3;
		else if (distance < 10000) coeff = 10;
		else coeff = 5;
		return distance * (1 - ((coeff) / 100)) / (MagicCarpet().get_speed());
	}
};

class Eagle : public AirTransport {
public:
	Eagle() : AirTransport(8,"Орёл", 6) {}
	double calc_time(double distance) override{
		return distance * (1 - (Eagle().get_coeff()) / 100) / (Eagle().get_speed());
	}
};

class Broom : public AirTransport {
public:
	Broom() : AirTransport(20, "Метла") {}
	double calc_time(double distance) override {
		return distance * (1 - ((floor(distance / 1000)) / (100))) / (Broom().get_speed());
	}
};

class Race {
private:
	double distance = 0;
	std::string type;
protected:
	Race(double distance_, std::string type_) : distance{ distance_ }, type{ type_ } {}
public:
	std::string get_type() {
		return type;
	}
};

class LandRace : public Race{
public:
	LandRace(double distance_) : Race(distance_, "Гонка для наземного транспорта") {}
};

class AirRace : public Race {
public:
	AirRace(double distance_) : Race(distance_, "Гонка для воздушного транспорта") {}
};

class LandAirRace : public Race {
public:
	LandAirRace(double distance_) : Race(distance_, "Гонка для наземного и воздушного транспорта") {}
};

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	LandRace LR(0); 
	AirRace AR(0); 
	LandAirRace LAR(0); 
	int type{}; 
	double distance{}; 
	int tmp{}, count{};
	Boots B; Broom BR; Camel C; Centaur CT; Eagle E; FastCamel FC; MagicCarpet MC;
	std::vector<std::pair<std::string, double>> res;
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
	while (true) {
		std::string reg_transport{ "Зарегистрированные транспортные средства: " };
		std::cout << "1. " << LR.get_type() << std::endl;
		std::cout << "2. " << AR.get_type() << std::endl;
		std::cout << "3. " << LAR.get_type() << std::endl;
		std::cout << "Выберите тип гонки: ";
		std::cin >> type;
		while (true) {
			if (type >= 1 && type <= 3) break;
			else {
				std::cout << "Попытка зарегистрировать неправильный тип гонки!" << std::endl;
				std::cout << "Выберите тип гонки: ";
				std::cin >> type;
			}
		}
		std::cout << "Укажите длину дистанции (должна быть положительна): ";
		std::cin >> distance;
		while (true) {
			if (distance > 0) break;
			else {
				std::cout << "Попытка указать отрицательную дистанцию!" << std::endl;
				std::cout << "Укажите длину дистанции (должна быть положительна): ";
				std::cin >> distance;
			}
		}
		std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
		std::cout << "1. Зарегистрировать транспорт" << std::endl;
		std::cout << "Выберите действие: ";
		std::cin >> tmp;
		while (true) {
			if (tmp == 1) break;
			else {
				std::cout << "Попытка указать неправильное действие!" << std::endl;
				std::cout << "Выберите действие: ";
				std::cin >> tmp;
			}
		}
		while (true) {
			switch (type) {
			case 1: std::cout << LR.get_type() << ". Расстояние: " << distance << std::endl; break;
			case 2: std::cout << AR.get_type() << ". Расстояние: " << distance << std::endl; break;
			default: std::cout << LAR.get_type() << ". Расстояние: " << distance << std::endl; break;
			}
			if (count >= 1) std::cout << reg_transport << std::endl;
			std::cout << "1. " << "Ботинки-вездеходы" << std::endl;
			std::cout << "2. " << "Метла" << std::endl;
			std::cout << "3. " << "Верблюд" << std::endl;
			std::cout << "4. " << "Кентавр" << std::endl;
			std::cout << "5. " << "Орёл" << std::endl;
			std::cout << "6. " << "Верблюд-быстроход" << std::endl;
			std::cout << "7. " << "Ковёр-самолёт" << std::endl;
			std::cout << "0. " << "Закончить регистрацию" << std::endl;
			std::cout << "Выберете транспорт или 0 для окончания процесса регистрации: ";
			std::cin >> tmp;
			if (tmp == 0 && count >= 2) {
				std::cout << "1. Зарегистрировать транспорт" << std::endl;
				std::cout << "2. Начать гонку" << std::endl;
				std::cout << "Выберите действие: ";
				std::cin >> tmp;
				while (true) {
					if (tmp == 1 || tmp == 2) break;
					else {
						std::cout << "Попытка выбрать несуществующее действие!" << std::endl;
						std::cout << "Выберите действие: ";
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
					std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства!" << std::endl;
					std::cout << "Выберете транспорт или 0 для окончания процесса регистрации: ";
					std::cin >> tmp;
					continue;
				}
				else {
					std::cout << "Попытка зарегистрировать несуществующее транспортное средство!" << std::endl;
					std::cout << "Выберете транспорт или 0 для окончания процесса регистрации: ";
					std::cin >> tmp;
				}
			}
			if (type == 1 && (tmp == 7 || tmp == 5 || tmp == 2)) {
				--count;
				std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
				continue;
			}
			else if (type == 2 && (tmp == 3 || tmp == 6 || tmp == 4 || tmp == 1)) {
				--count;
				std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
				continue;
			}
			switch (tmp) {
			case 1: 
				  B.set_count((B.get_count()) + 1);
				  if (B.get_count() > 1) {
					  std::cout << B.get_type() << " уже зарегистрированы!" << std::endl;
					  B.set_count(B.get_count() - 1);
					  break;
				  }
				  std::cout << B.get_type() << " успешно зарегистрированы!" << std::endl;
				  reg_transport += (count == 1) ? B.get_type() : ", " + B.get_type();
				  break;
			case 2:
				BR.set_count((BR.get_count()) + 1);
				if (BR.get_count() > 1) {
					std::cout << BR.get_type() << " уже зарегистрирована!" << std::endl;
					BR.set_count(BR.get_count() - 1);
					break;
				}
				std::cout << BR.get_type() << " успешно зарегистрирована!" << std::endl;
				reg_transport += (count == 1) ? BR.get_type() : ", " + BR.get_type();
				break;
			case 3:
				C.set_count((C.get_count()) + 1);
				if (C.get_count() > 1) {
					std::cout << C.get_type() << " уже зарегистрирован!" << std::endl;
					C.set_count(C.get_count() - 1);
					break;
				}
				std::cout << C.get_type() << " успешно зарегистрирован!" << std::endl;
				C.set_count(1);
				reg_transport += (count == 1) ? C.get_type() : ", " + C.get_type();
				break;
			case 4:
				CT.set_count((CT.get_count()) + 1);
				if (CT.get_count() > 1) {
					std::cout << CT.get_type() << " уже зарегистрирован!" << std::endl;
					CT.set_count(CT.get_count() - 1);
					break;
				}
				std::cout << CT.get_type() << " успешно зарегистрирован!" << std::endl;
				reg_transport += (count == 1) ? CT.get_type() : ", " + CT.get_type();
				break;
			case 5:
				E.set_count((E.get_count()) + 1);
				if (E.get_count() > 1) {
					std::cout << E.get_type() << " уже зарегистрирован!" << std::endl;
					E.set_count(E.get_count() - 1);
					break;
				}
				std::cout << E.get_type() << " успешно зарегистрирован!" << std::endl;
				reg_transport += (count == 1) ? E.get_type() : ", " + E.get_type();
				break;
			case 6:
				FC.set_count((FC.get_count()) + 1);
				if (FC.get_count() > 1) {
					std::cout << FC.get_type() << " уже зарегистрирован!" << std::endl;
					FC.set_count(FC.get_count() - 1);
					break;
				}
				std::cout << FC.get_type() << " успешно зарегистрирован!" << std::endl;
				reg_transport += (count == 1) ? FC.get_type() : ", " + FC.get_type();
				break;
			case 7:
				MC.set_count((MC.get_count()) + 1);
				if (MC.get_count() > 1) {
					std::cout << MC.get_type() << " уже зарегистрирован!" << std::endl;
					MC.set_count(MC.get_count() - 1);
					break;
				}
				std::cout << MC.get_type() << " успешно зарегистрирован!" << std::endl;
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
		std::cout << "Результаты гонки:" << std::endl;
		for (size_t i{}; i < res.size(); ++i) {
			std::cout << i + 1 << ". " << res[i].first << ". Время: " << res[i].second << std::endl;
		}
		std::cout << std::endl;
		std::cout << "1. Провести ещё одну гонку" << std::endl;
		std::cout << "2. Выйти" << std::endl;
		std::cout << "Выберите действие: ";
		std::cin >> tmp;
		while (true) {
			if (tmp == 1 || tmp == 2) break;
			else {
				std::cout << "Попытка выбрать несуществующее действие!" << std::endl;
				std::cout << "Выберите действие: ";
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

