#include "Transporter.h"
#include "UsersInput.h"
#include <iostream>
#include <fstream>

using namespace std;

void startInput(Transporter& transporter);
void printMenu();
void addObject(Transporter& transporter);
void changeObject(Transporter& transporter);
void deleteObject(Transporter& transporter);
void printTransporter(Transporter& transporter);
void inputFromFile(Transporter& transporter, ifstream& file);
void inputFromConsole(Transporter& transporter);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Transporter transporter;

	startInput(transporter);
	
	bool isExit = false;
	while (!isExit) {
		printMenu();

		int method = processingInput(0, 5);
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
			break;
		case 5:
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
	cout << "4. Сохранить в файл" << endl;
	cout << "5. Вывести данные" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";
}

void addObject(Transporter& transporter) {
	cout << "Выберете объкт для добавления: " << endl;
	int method = chouseObject();
	if (method == 1) {
		Plane plane = inputPlane();
		transporter.addObject(plane);
	}
	else if (method == 2) {
		Car car = inputCar();
		transporter.addObject(car);
	}
	else if (method == 3) {
		Train train = inputTrain();
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
			changePlane(plane);
			transporter.changeObject(plane, index);
		}
		else {
			cout << "Список самолетов пуст. Нечего изменять" << endl;
		}
		break;
	case 2:
		if (transporter.getCountCars() > 0) {
			transporter.printCars(cout);
			cout << "Введите номер автомобиля для изменения: ";
			int index = processingInput(1, transporter.getCountCars()) - 1;
			Car car = transporter.getCars()[index];
			changeCar(car);
			transporter.changeObject(car, index);
		}
		else {
			cout << "Список автомобилей пуст. Нечего изменять" << endl;
		}
		break;
	case 3:
		if (transporter.getCountTrains() > 0) {
			transporter.printTrains(cout);
			cout << "Введите номер поезда для изменения: ";
			int index = processingInput(1, transporter.getCountTrains()) - 1;
			Train train = transporter.getTrains()[index];
			changeTrain(train);
			transporter.changeObject(train, index);
		}
		else {
			cout << "Список поездов пуст. Нечего изменять" << endl;
		}
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
		else {
			cout << "Список самолетов пуст. Нечего удалять" << endl;
		}
		break;
	case 2:
		if (transporter.getCountCars() > 0) {
			transporter.printCars(cout);
			cout << "Введите номер автомобиля для удаления: ";
			transporter.deleteCar(processingInput(1, transporter.getCountCars()) - 1);
		}
		else {
			cout << "Список автомобилей пуст. Нечего удалять" << endl;
		}
		break;
	case 3:
		if (transporter.getCountTrains() > 0) {
			transporter.printTrains(cout);
			cout << "Введите номер поезда для удаления: ";
			transporter.deleteTrain(processingInput(1, transporter.getCountTrains()) - 1);
		}
		else {
			cout << "Список поездов пуст. Нечего удалять" << endl;
		}
		break;
	}
}

void printTransporter(Transporter& transporter) {
	cout << "Выберете место вывода: " << endl;
	int method = chouseStream();
	if (method == 1) {
		ofstream file(processInputNameOfOutputFile());
		transporter.print(file);
		file.close();
	}
	else if (method == 2) {
		transporter.print(cout);
	}
}

void startInput(Transporter& transporter) {
	cout << "Откуда ввести данные: " << endl;
	int method = chouseStream();
	if (method == 1) {
		ifstream file;
		if (processInputNameOfInputFile(file))
			inputFromFile(transporter, file);
	}
	else if (method == 2) {
		inputFromConsole(transporter);
	}
}

void inputFromFile(Transporter& transporter, ifstream& file) {
	
}

void inputFromConsole(Transporter& transporter) {
	cout << "Введите количество самолетов: ";
	int count  = processingInput(0, INT32_MAX);
	for (int i = 0; i < count; i++) {
		Plane plane = inputPlane();
		transporter.addObject(plane);
	}

	cout << "Введите количество автомобилей: ";
	count = processingInput(0, INT32_MAX);
	for (int i = 0; i < count; i++) {
		Car car = inputCar();
		transporter.addObject(car);
	}

	cout << "Введите количество поездов: ";
	count = processingInput(0, INT32_MAX);
	for (int i = 0; i < count; i++) {
		Train train = inputTrain();
		transporter.addObject(train);
	}
}

