#include "Transporter.h"

Transporter::Transporter(MyArray<Plane> _planes, MyArray<Car> _cars, MyArray<Train> _trains) :
	planes(_planes), cars(_cars), trains(_trains)
	{ Logger::printBuilder("Transporter"); }

Transporter::Transporter(const Transporter& transporter) :
	planes(transporter.planes), cars(transporter.cars), trains(transporter.trains)
	{ Logger::printCopyBuilder("Transporter"); }

void Transporter::addObject(Plane& plane) { planes.add(plane); }
void Transporter::addObject(Car& car) { cars.add(car); }
void Transporter::addObject(Train& train) { trains.add(train); }

void Transporter::changeObject(Plane& plane, int index) { planes[index] = plane; }
void Transporter::changeObject(Car& car, int index) { cars[index] = car; }
void Transporter::changeObject(Train& train, int index) { trains[index] = train; }

void Transporter::deletePlane(int index) { planes.del(index); }
void Transporter::deleteCar(int index) { cars.del(index); }
void Transporter::deleteTrain(int index) { trains.del(index); }

void Transporter::print(std::ostream& out) {

	if (planes.getSize() > 0 || cars.getSize() > 0 || trains.getSize() > 0) {
		out << "Список объектов:" << std::endl;
		/*for (int i = 0; i < planes.getSize(); i++)
			planes[i].print(out, " " + std::to_string(i + 1));
		for (int i = 0; i < cars.getSize(); i++)
			cars[i].print(out, " " + std::to_string(i + 1));
		for (int i = 0; i < cars.getSize(); i++)
			cars[i].print(out, " " + std::to_string(i + 1));*/
		printPlanes(out);
		printCars(out);
		printTrains(out);
	}
	else
		out << "У грузоперевозчика нет объектов" << std::endl;
}

void Transporter::printPlanes(std::ostream& out) {
	for (int i = 0; i < planes.getSize(); i++)
		planes[i].print(out, " " + std::to_string(i + 1));
}

void Transporter::printCars(std::ostream& out) {
	for (int i = 0; i < cars.getSize(); i++)
		cars[i].print(out, " " + std::to_string(i + 1));
}

void Transporter::printTrains(std::ostream& out) {
	for (int i = 0; i < trains.getSize(); i++)
		trains[i].print(out, " " + std::to_string(i + 1));
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