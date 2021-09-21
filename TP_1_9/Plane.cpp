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
	out << "�������" << number << ":" << std::endl;
	out << "��� = " << type << std::endl;
	out << "������������ = " << name << std::endl;
	out << "����� ����� = " << volumeWeid << std::endl;
	out << "������������ ����� ����� = " << lengt << std::endl;
	out << "������������ ������ ����� = "  << width << std::endl;
	out << "������������ ������ ����� = "  << height << std::endl;
	if (towns.getSize() > 0) {
		out << "������ �������:" << std::endl;
		for (int i = 0; i < towns.getSize(); i++)
			out << "�������� ������ " << i + 1 << " = " << towns[i] << std::endl;
	}
	else
		out << "������ ������� �� ������" << std::endl;
	
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
