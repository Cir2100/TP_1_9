#pragma once
#include "Base.h"
#include "CarsTown.h"

class Car :
    public Base
{

private:

	int yearRelease;
	std::string mark, model;
	CarsTown* towns;

public:
	Car(double volumeWeid = 0, double type = 1) { printBuilder("Car"); };
	Car(const Car& car) { printBuilder("Car"); };
	~Car() { printDeconstuctor("Car"); };

	virtual void print(std::ostream& out);
	virtual void input(std::istream& in);
};

