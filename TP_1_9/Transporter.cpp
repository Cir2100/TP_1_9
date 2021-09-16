#include "Transporter.h"

Transporter::Transporter(MyArray<Plane> _planes, MyArray<Car> _cars, MyArray<Train> _trains) :
	planes(_planes), cars(_cars), trains(_trains)
	{ Logger::printBuilder("Transporter"); }

Transporter::Transporter(const Transporter& transporter) :
	planes(transporter.planes), cars(transporter.cars), trains(transporter.trains)
	{ Logger::printCopyBuilder("Transporter"); }

void Transporter::addBase(Plane& plane) { planes.add(plane); }
void Transporter::addBase(Car& car) { cars.add(car); }
void Transporter::addBase(Train& train) { trains.add(train); }

void Transporter::print(std::ostream& out) {

	if (planes.getSize() > 0 || cars.getSize() > 0 || trains.getSize() > 0) {
		out << "Список объектов:" << std::endl;
		for (int i = 0; i < planes.getSize(); i++)
			planes[i].print(out);
		for (int i = 0; i < cars.getSize(); i++)
			cars[i].print(out);
		for (int i = 0; i < trains.getSize(); i++)
			trains[i].print(out);
	}
	else
		out << "У грузоперевозчика нет объектов" << std::endl;
}

Transporter& Transporter::operator=(const Transporter& transporter)
{
	if (this == &transporter)
		return *this;
	planes = transporter.planes;
	cars = transporter.cars;
	trains = transporter.trains;
	return *this;
}