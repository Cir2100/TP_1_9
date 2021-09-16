#pragma once
#include "Transporter.h"
#include <iostream>
#include <fstream>

template <typename T>
T processingInput(T minInput, T maxInput);
template <typename T>
void inputData(std::string help, T& data, T minValue, T maxValue);
int chouseStream();
int chouseObject();
bool processInputNameOfInputFile(std::ifstream& file);
std::string processInputNameOfOutputFile();
bool checkFilename(std::string file);
Plane inputPlane();
Car inputCar();
Train inputTrain();
void changePlane(Plane& plane);
void changeCar(Car& car);
void changeTrain(Train& train);
void inputTowns(MyArray<std::string>& towns);
void inputTowns(MyArray<CarsTown>& towns);
void inputData(std::string help, std::string& data);

template <typename T>
T processingInput(T minInput, T maxInput) {
	while (true)
	{
		T method;
		std::cin >> method;
		if (std::cin.fail() || method < minInput || method > maxInput)
		{
			std::cin.clear();
			std::cout << "¬ведено неверное число.\n¬ведите повторно: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cin.clear();
			return method;
		}
		std::cin.ignore(32767, '\n');
	}
}

template <typename T>
void inputData(std::string help, T& data, T minValue, T maxValue) {
	std::cout << help;
	data = processingInput(minValue, maxValue);
}
