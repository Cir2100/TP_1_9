#pragma once
#include "Plane.h"
#include "Car.h"
#include "Train.h"
#include "MyArray.h"
#include <iostream>

class Transporter
{
private:
	MyArray<Plane> planes;
	MyArray<Car> cars;
	MyArray<Train> trains;
public:

	Transporter(MyArray<Plane> _planes = MyArray<Plane>(),
		MyArray<Car> _cars = MyArray<Car>(), MyArray<Train> _trains = MyArray<Train>());
	Transporter(const Transporter& transporter);
	~Transporter() { Logger::printDeconstuctor("Transporter"); }

	void addObject(Plane& plane);
	void addObject(Car& car);
	void addObject(Train& train);

	void changeObject(Plane& plane, int index);
	void changeObject(Car& car, int index);
	void changeObject(Train& train, int index);

	void deletePlane(int index);
	void deleteTrain(int index);

	void print(std::ostream& out);
	void printPlanes(std::ostream& out);
	void printCars(std::ostream& out);
	void printTrains(std::ostream& out);
	//virtual void input(std::istream& in);
	Transporter& operator=(const Transporter& transporter);

	MyArray<Plane> getPlanes() { return planes; }
	void setPlanes(MyArray<Plane> _planes) { planes = _planes; }
	int getCountPlanes() { return planes.getSize(); }

	MyArray<Car> getCars() { return cars; }
	void setCars(MyArray<Car> _cars) { cars = _cars; }
	int getCountCars() { return cars.getSize(); }

	MyArray<Train> getTrains() { return trains; }
	void setTrains(MyArray<Train> _trains) { trains = _trains; }
	int getCountTrains() { return trains.getSize(); }
};

