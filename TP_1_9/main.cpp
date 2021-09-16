#include "Transporter.h"
#include "UsersInput.h"
#include <iostream>
#include <fstream>

using namespace std;

void startInput(Transporter& transporter);
void printMenu();
void addObject(Transporter& transporter);
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
			break;
		case 3:
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
	cout << "1. �������� �����" << endl;
	cout << "2. �������� ������" << endl;
	cout << "3. ������� ������" << endl;
	cout << "4. ��������� � ����" << endl;
	cout << "5. ������� ������" << endl;
	cout << "0. �����" << endl;
	cout << "�������� ����� ����: ";
}

void addObject(Transporter& transporter) {
	cout << "�������� ����� ��� ����������: " << endl;
	int method = chouseObject();
	if (method == 1) {
		Plane plane = inputPlane();
		transporter.addBase(plane);
	}
	else if (method == 2) {
		Car car = inputCar();
		transporter.addBase(car);
	}
	else if (method == 3) {
		Train train = inputTrain();
		transporter.addBase(train);
	}
}

void printTransporter(Transporter& transporter) {
	cout << "�������� ����� ������: " << endl;
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
	cout << "������ ������ ������: " << endl;
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
	cout << "������� ���������� ���������: ";
	int count  = processingInput(0, INT32_MAX);
	for (int i = 0; i < count; i++) {
		Plane plane = inputPlane();
		transporter.addBase(plane);
	}

	cout << "������� ���������� �����������: ";
	count = processingInput(0, INT32_MAX);
	for (int i = 0; i < count; i++) {
		Car car = inputCar();
		transporter.addBase(car);
	}

	cout << "������� ���������� �������: ";
	count = processingInput(0, INT32_MAX);
	for (int i = 0; i < count; i++) {
		Train train = inputTrain();
		transporter.addBase(train);
	}
}

