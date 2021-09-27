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
	out << TRAIN_STRING << number << ":" << std::endl;
	out << NAME_STRING << " = " << name << std::endl;
	out << VOLUME_WEID_STRING << " = " << volumeWeid << std::endl;
	out << YEAR_RELISE_STRING << " = " << yearRelease << std::endl;
	out << COUNT_WAGONS_STRING << " = " << countWagons << std::endl;
	if (route.getSize() > 0) {
		out << TOWN_LIST_STRING << std::endl;
		for (int i = 0; i < route.getSize(); i++)
			out << TOWN_NAME_STRING << i + 1 << " = " << route[i] << std::endl;
	}
	else
		out << EMPTY_TOWN_LIST_STRING << std::endl;
		
	out << std::endl;
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