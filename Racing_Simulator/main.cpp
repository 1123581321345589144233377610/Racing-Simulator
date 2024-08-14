#include <iostream>
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
protected:
	LandTransport(double speed_, double driving_time_before_rest_, double duration_of_rest1_, double duration_of_rest2_, double duration_of_rest3_, std::string type_) : speed{ speed_ }, driving_time_before_rest{ driving_time_before_rest_ }, duration_of_rest1{ duration_of_rest1_ }, duration_of_rest2{ duration_of_rest2_ }, duration_of_rest3{ duration_of_rest3_ }, type{ type_ } {}
public:
	std::string get_type(){
		return type;
	}
};


class Camel : public LandTransport {
public:
	Camel() : LandTransport(10, 30, 5, 8, 8, "�������") {}
};

class FastCamel : public LandTransport {
public:
	FastCamel() : LandTransport(40, 10, 5, 6.5, 8, "�������-���������") {}
};

class Centaur : LandTransport {
public:
	Centaur() : LandTransport(15, 8, 2, 2, 2, "�������") {}
};

class Boots : public LandTransport {
public:
	Boots() : LandTransport(6, 60, 10, 5, 5, "�������-���������") {}
};

class AirTransport : public Transport {
private:
	double speed = 0;
	double coeff = 0;
	std::string type;
protected:
	AirTransport(double speed_, std::string type_) : speed{ speed_ }, type{ type_ } {}
	AirTransport(double speed_, std::string type_, double coeff_) : speed{ speed_ }, type{ type_ }, coeff { coeff_ } {}
public:
	std::string get_type() {
		return type;
	}
};

class MagicCarpet : public AirTransport {
public:
	MagicCarpet() : AirTransport(10, "����-������") {}
};

class Eagle : public AirTransport {
public:
	Eagle() : AirTransport(8,"���", 6) {}
};

class Broom : public AirTransport {
public:
	Broom() : AirTransport(20, "�����") {}
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
	LandRace(double distance_) : Race(distance_, "����� ��� ��������� ����������") {}
};

class AirRace : public Race {
public:
	AirRace(double distance_) : Race(distance_, "����� ��� ���������� ����������") {}
};

class LandAirRace : public Race {
public:
	LandAirRace(double distance_) : Race(distance_, "����� ��� ��������� � ���������� ����������") {}
};

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	LandRace LR(0); AirRace AR(0); LandAirRace LAR(0); int type{}; double distance{}; int tmp{};
	std::cout << "����� ���������� � �������� ���������!" << std::endl;
	while (true) {
		std::cout << "1. " << LR.get_type() << std::endl;
		std::cout << "2. " << AR.get_type() << std::endl;
		std::cout << "3. " << LAR.get_type() << std::endl;
		std::cout << "�������� ��� �����: ";
		std::cin >> type;
		while (true) {
			if (type >= 1 && type <= 3) break;
			else {
				std::cout << "������� ���������������� ������������ ��� �����!" << std::endl;
				std::cout << "�������� ��� �����: ";
				std::cin >> type;
			}
		}
		std::cout << "������� ����� ��������� (������ ���� ������������): ";
		std::cin >> distance;
		while (true) {
			if (distance > 0) break;
			else {
				std::cout << "������� ������� ������������� ���������!" << std::endl;
				std::cout << "������� ����� ��������� (������ ���� ������������): ";
				std::cin >> distance;
			}
		}
		std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������" << std::endl;
		std::cout << "1. ���������������� ���������" << std::endl;
		std::cout << "�������� ��������: ";
		std::cin >> tmp;
		while (true) {
			if (tmp == 1) break;
			else {
				std::cout << "������� ������� ������������ ��������!" << std::endl;
				std::cout << "�������� ��������: ";
				std::cin >> tmp;
			}
		}
	}
	return 0;
}