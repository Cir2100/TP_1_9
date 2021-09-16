#pragma once
#include "Base.h"
#include "Plane.h"
#include "Car.h"
#include "Train.h"
#include "Strings.h"
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

	void addBase(Plane& plane);
	void addBase(Car& car);
	void addBase(Train& train);

	void print(std::ostream& out);
	//virtual void input(std::istream& in);
	Transporter& operator=(const Transporter& transporter);

	MyArray<Plane> getPlanes() { return planes; }
	void setPlanes(MyArray<Plane> _planes) { planes = _planes; }

	MyArray<Car> getCars() { return cars; }
	void setCars(MyArray<Car> _cars) { cars = _cars; }

	MyArray<Train> getTrains() { return trains; }
	void setTrains(MyArray<Train> _trains) { trains = _trains; }
};

