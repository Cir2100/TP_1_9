#include "Car.h"

Car::Car(std::string _mark, std::string _model, int _yearRelease, MyArray<CarsTown> _towns)
	: mark(_mark), model(_model), yearRelease(_yearRelease), towns(_towns)
	{ Logger::printBuilder("Car"); }

Car::Car(const Car& car)
	: mark(car.mark), model(car.model), yearRelease(car.yearRelease), towns(car.towns)
	{ Logger::printCopyBuilder("Car"); }

void Car::print(std::ostream& out, std::string number) {
	out << CAR_STRING << number << ":" << std::endl;
	out << MARK_STRING << " = " << mark << std::endl;
	out << MODEL_STRING << " = " << model << std::endl;
	out << YEAR_RELISE_STRING << " = " << yearRelease << std::endl;
	if (towns.getSize() > 0) {
		out << TOWN_LIST_STRING << std::endl;
		for (int i = 0; i < towns.getSize(); i++) {
			out << TOWN_NAME_STRING << i + 1 << " = " << towns[i].name << std::endl;
			out << "  " << TOWN_WAY_HOURS_STRING << i + 1 << " = " << towns[i].wayHours << std::endl;
			out << "  " << TOWN_VOLUME_WEID_STRING << i + 1 << " = " << towns[i].volumeWeid << std::endl;
		}	
	}
	else
		out << EMPTY_TOWN_LIST_STRING << std::endl;

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