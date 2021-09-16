#include "Train.h"

Train::Train(std::string _name, double _volumeWeid, int _yearRelease, int _countWagons, MyArray<std::string> _route)
	: name(_name), volumeWeid(_volumeWeid), yearRelease(_yearRelease),
	countWagons(_countWagons), route(_route)
	{ Logger::printBuilder("Train"); }

Train::Train(const Train& train)
	: name(train.name), volumeWeid(train.volumeWeid), yearRelease(train.yearRelease),
	countWagons(train.countWagons), route(train.route)
	{ Logger::printCopyBuilder("Train"); }

void Train::print(std::ostream& out, std::string number) {
	out << "Поезд" << number << ":" << std::endl;
	out << "Наименование = " << name << std::endl;
	out << "Объем груза = " << volumeWeid << std::endl;
	out << "Год релиза = " << yearRelease << std::endl;
	out << "Количчество вагонов = " << countWagons << std::endl;
	if (route.getSize() > 0) {
		out << "Маршрут поезда:" << std::endl;
		for (int i = 0; i < route.getSize(); i++)
			out << "  " << route[i] << std::endl;
	}
	else
		out << "Маршрут не указан" << std::endl;
		
	out << std::endl;
}

void Train::input(std::istream& in) {
	//in >> volumeWeid;
	//in >> type;
}

Train& Train::operator=(const Train& train)
{
	if (this == &train)
		return *this;
	name = train.name;
	volumeWeid = train.volumeWeid;
	yearRelease = train.yearRelease;
	countWagons = train.countWagons;
	route = train.route;
	return *this;
}