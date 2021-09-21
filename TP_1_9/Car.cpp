#include "Car.h"

Car::Car(std::string _mark, std::string _model, int _yearRelease, MyArray<CarsTown> _towns)
	: mark(_mark), model(_model), yearRelease(_yearRelease), towns(_towns)
	{ Logger::printBuilder("Car"); }

Car::Car(const Car& car)
	: mark(car.mark), model(car.model), yearRelease(car.yearRelease), towns(car.towns)
	{ Logger::printCopyBuilder("Car"); }

void Car::print(std::ostream& out, std::string number) {
	out << "����������" << number << ":" << std::endl;
	out << "����� = " << mark << std::endl;
	out << "������ = " << model << std::endl;
	out << "��� ������ = " << yearRelease << std::endl;
	if (towns.getSize() > 0) {
		out << "������ �������:" << std::endl;
		for (int i = 0; i < towns.getSize(); i++) {
			out << "�������� ������ " << i + 1 << " = " << towns[i].name << std::endl;
			out << "  ����� � ���� ��� ������ " << i + 1 << " = " << towns[i].wayHours << std::endl;
			out << "  ����� ����� ��� ������ " << i + 1 << " = " << towns[i].volumeWeid << std::endl;
		}	
	}
	else
		out << "������ ������� �� ������" << std::endl;

	out << std::endl;
}

Car& Car::operator=(const Car& car)
{
	if (this == &car)
		return *this;
	yearRelease = car.yearRelease;
	mark = car.mark;
	model = car.model;
	towns = car.towns;
	return *this;
}