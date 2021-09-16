#include "Transporter.h"
#include "Car.h"
#include "Plane.h"
#include "Train.h"
#include "MyArray.h"
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void addBase(Transporter& transporter) {
	MyArray<std::string> a;
	a.add("sdfsdf");
	a.add("dsgdsf");
	a.add("ghkhg");
	Plane plane("type", "name", 10, 1, 2, 3, a);
	Train train("name", 100.34, 1900, 2, a);
	MyArray<CarsTown> towns;
	towns.add(CarsTown("name", 12.3, 3));
	Car car("mark", "model", 1900, towns);
	transporter.addBase(plane);
	transporter.addBase(train);
	transporter.addBase(car);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ofstream filename("save.txt");

	Transporter transporter;
	//transporter.addBase(plane);
	addBase(transporter);
	transporter.print(cout);
	transporter.print(filename);
	
}