#include "Transporter.h"
#include "UsersInput.h"
#include "FileInput.h"
#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

void startInput(Transporter& transporter);
void printMenu();
void addObject(Transporter& transporter);
void changeObject(Transporter& transporter);
void deleteObject(Transporter& transporter);
void printTransporter(Transporter& transporter);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Transporter transporter;

	startInput(transporter);
	
	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = processingInput(0, 4);
		switch (method)
		{
		case 1:
			addObject(transporter);
			break;
		case 2:
			changeObject(transporter);
			break;
		case 3:
			deleteObject(transporter);
			break;
		case 4:
			printTransporter(transporter);
			break;
		case 0:
			isExit = true;
			break;
		}
	}

}

void printMenu() {
	cout << "1. Добавить оъект" << endl;
	cout << "2. Изменить объект" << endl;
	cout << "3. Удалить объект" << endl;
	cout << "4. Вывести данные" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";
}

void addObject(Transporter& transporter) {
	cout << "Выберете объкт для добавления: " << endl;
	int method = chouseObject();
	if (method == 1) {
		Plane plane;
		plane.inputFromConsole();
		transporter.addObject(plane);
	}
	else if (method == 2) {
		Car car;
		car.inputFromConsole();
		transporter.addObject(car);
	}
	else if (method == 3) {
		Train train;
		train.inputFromConsole();
		transporter.addObject(train);
	}
}

void changeObject(Transporter& transporter) {
	cout << "Выберете объкт для изменения: " << endl;
	int method = chouseObject();
	
	switch (method)
	{
	case 1:
		if (transporter.getCountPlanes() > 0) {
			transporter.printPlanes(cout);
			cout << "Введите номер самолета для изменения: ";
			int index = processingInput(1, transporter.getCountPlanes()) - 1;
			Plane plane = transporter.getPlanes()[index];
			plane.change();
			transporter.changeObject(plane, index);
		}
		else
			Logger::printWarning("Список самолетов пуст. Нечего изменять");
		break;
	case 2:
		if (transporter.getCountCars() > 0) {
			transporter.printCars(cout);
			cout << "Введите номер автомобиля для изменения: ";
			int index = processingInput(1, transporter.getCountCars()) - 1;
			Car car = transporter.getCars()[index];
			car.change();
			transporter.changeObject(car, index);
		}
		else
			Logger::printWarning("Список автомобилей пуст. Нечего изменять");
		break;
	case 3:
		if (transporter.getCountTrains() > 0) {
			transporter.printTrains(cout);
			cout << "Введите номер поезда для изменения: ";
			int index = processingInput(1, transporter.getCountTrains()) - 1;
			Train train = transporter.getTrains()[index];
			train.change();
			transporter.changeObject(train, index);
		}
		else
			Logger::printWarning("Список поездов пуст. Нечего изменять");
		break;
	}
}

void deleteObject(Transporter& transporter) {
	cout << "Выберете объкт для удаления: " << endl;
	int method = chouseObject();
	
	switch (method)
	{
	case 1:
		if (transporter.getCountPlanes() > 0) {
			transporter.printPlanes(cout);
			cout << "Введите номер самолета для удаления: ";
			transporter.deletePlane(processingInput(1, transporter.getCountPlanes()) - 1);
		}
		else
			Logger::printWarning("Список самолетов пуст. Нечего удалять");
		break;
	case 2:
		if (transporter.getCountCars() > 0) {
			transporter.printCars(cout);
			cout << "Введите номер автомобиля для удаления: ";
			transporter.deleteCar(processingInput(1, transporter.getCountCars()) - 1);
		}
		else
			Logger::printWarning("Список автомобилей пуст. Нечего удалять");
		break;
	case 3:
		if (transporter.getCountTrains() > 0) {
			transporter.printTrains(cout);
			cout << "Введите номер поезда для удаления: ";
			transporter.deleteTrain(processingInput(1, transporter.getCountTrains()) - 1);
		}
		else
			Logger::printWarning("Список поездов пуст. Нечего удалять");
		break;
	}
}

void printTransporter(Transporter& transporter) {
	cout << "Выберете место вывода: " << endl;
	int method = chouseStream();
	if (method == 1) {
		string filename;
		if (processInputNameOfOutputFile(filename)) {
			ofstream file(filename);
			transporter.print(file, filename.substr(filename.find_last_of(".")));
			file.close();
		}	
	}
	else if (method == 2) {
		string filename;
		if (processInputNameOfOutputFile(filename))
			transporter.codeToFile(filename);
	}
	else if (method == 3) {
		transporter.print(cout);
	}
}

void startInput(Transporter& transporter) {
	cout << "Откуда ввести данные: " << endl;
	int method = chouseStream();
	if (method == 1) {
		string filename;
		if (processInputNameOfInputFile(filename))
			transporter.inputFromFile(filename);
	}
	else if (method == 2) {
		string filename;
		if (processInputNameOfInputFile(filename))
			transporter.inputFromCodeFile(filename);
	}
	else if (method == 3) {
		transporter.inputFromConsole();
	}
}

