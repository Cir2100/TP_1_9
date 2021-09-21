#include "Plane.h"

Plane::Plane(std::string _type, std::string _name, double _volumeWeid, double _width,
	double _lengt, double _height, MyArray<std::string> _towns)
	: type(_type), name(_name), volumeWeid(_volumeWeid), width(_width),
	lengt(_lengt), height(_height), towns(_towns) 
	{ Logger::printBuilder("Plane"); }

Plane::Plane(const Plane& plane) :
	type(plane.type), name(plane.name), volumeWeid(plane.volumeWeid), width(plane.width),
	lengt(plane.lengt), height(plane.height), towns(plane.towns)
	{ Logger::printCopyBuilder("Plane"); }

void Plane::print(std::ostream& out, std::string number) {
	out << "Самолет" << number << ":" << std::endl;
	out << "Тип = " << type << std::endl;
	out << "Наименование = " << name << std::endl;
	out << "Объем груза = " << volumeWeid << std::endl;
	out << "Максимальная длина груза = " << lengt << std::endl;
	out << "Максимальная ширина груза = "  << width << std::endl;
	out << "Максимальная высота груза = "  << height << std::endl;
	if (towns.getSize() > 0) {
		out << "Список городов:" << std::endl;
		for (int i = 0; i < towns.getSize(); i++)
			out << "Название города " << i + 1 << " = " << towns[i] << std::endl;
	}
	else
		out << "Список городов не указан" << std::endl;
	
	out << std::endl;
}

Plane& Plane::operator=(const Plane& plane)
{
	if (this == &plane)
		return *this;
	type = plane.type;
	name = plane.name;
	volumeWeid = plane.volumeWeid;
	width = plane.width;
	lengt = plane.lengt;
	height = plane.height;
	towns = plane.towns;
	return *this;
}
