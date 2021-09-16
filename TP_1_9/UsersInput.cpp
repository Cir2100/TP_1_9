#include "UsersInput.h"


int chouseStream() {
	std::cout << "1. ����" << std::endl;
	std::cout << "2. �������" << std::endl;
	std::cout << "0. ������" << std::endl;
	return processingInput(0, 2);
}

int chouseObject() {
	std::cout << "1. �������" << std::endl;
	std::cout << "2. ����������" << std::endl;
	std::cout << "3. �����" << std::endl;
	std::cout << "0. ������" << std::endl;
	return processingInput(0, 3);
}

//��������� ����� �������� ����a
//���� 0 �������� ����� �� ����� ������ �� �����.
bool processInputNameOfInputFile(std::ifstream& file)
{
	//��������� �������� �����
	std::string filename;
	bool isCorrect;
	std::cout << "������� �������� ����� (� �����������): ";
	std::cin >> filename;
	isCorrect = checkFilename(filename);
	if (isCorrect)
		file.open(filename);
	while (!file.is_open() && filename[0] != '0')
	{
		if (isCorrect)
			std::cout << "������ ����� �� ����������." << std::endl;
		std::cout << "������� �������� �������� (� �����������): ";
		std::cin >> filename;
		isCorrect = checkFilename(filename);
		if (isCorrect)
			file.open(filename);
	}
	if (filename[0] != '0') {
		std::cout << "���� ������� ������" << std::endl;
		return true;
	}
	else {
		std::cout << "�� ���������� �� ����� ������ �� �����" << std::endl;
		return false;
	}
		
}
//��������� ����� ��������� ����a
//���� 0 �������� ����� �� ����� ������ �� �����.
std::string processInputNameOfOutputFile()
{
	//��������� �������� �����
	std::string filename;
	bool isCorrect;
	std::cout << "������� �������� ����� (� �����������): ";
	std::cin >> filename;
	isCorrect = checkFilename(filename);
	while (!isCorrect) {
		std::cin >> filename;
		isCorrect = checkFilename(filename);
	}
	return filename;
}
//�������� ������������ ����� �����
bool checkFilename(std::string file)
{
	if ((((file[0] == 'c') || (file[0] == 'C')) && ((file[1] == 'o') || (file[1] == 'O'))
		&& ((file[2] == 'n') || (file[2] == 'N')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'a') || (file[0] == 'A')) && ((file[1] == 'u') || (file[1] == 'U'))
			&& ((file[2] == 'x') || (file[2] == 'X')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'p') || (file[0] == 'P')) && ((file[1] == 'r') || (file[1] == 'R'))
			&& ((file[2] == 'n') || (file[2] == 'N')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'c') || (file[0] == 'C')) && ((file[1] == 'o') || (file[1] == 'O'))
			&& ((file[2] == 'm') || (file[2] == 'M')) && ((file[3] == '1') || (file[3] == '2')
				|| (file[3] == '3') || (file[3] == '4') || (file[3] == '5') || (file[3] == '6')
				|| (file[3] == '7') || (file[3] == '8') || (file[3] == '9')) && ((file[4] == '.')
					|| (file[4] == '\0'))) || (((file[0] == 'l') || (file[0] == 'L')) && ((file[1] == 'p')
						|| (file[1] == 'P')) && ((file[2] == 't') || (file[2] == 'T')) && ((file[3] == '1')
							|| (file[3] == '2') || (file[3] == '3') || (file[3] == '4') || (file[3] == '5')
							|| (file[3] == '6') || (file[3] == '7') || (file[3] == '8') || (file[3] == '9'))
						&& ((file[4] == '.') || (file[4] == '\0'))))
	{
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "������ ��� ����� ������������ Windows." << std::endl;
		return false;
	}
	int i = file.size();
	if ((file[i] == '\0') && (file[i - 1] == 't') && (file[i - 2] == 'x') && (file[i - 3] == 't') && (file[i - 4] == '.'))
		return true;
	else
	{
		if (file[i - 1] != '0')
			std::cout << "���� ������ ����� ������ .txt" << std::endl;
		return false;
	}
}

Plane inputPlane() {
	std::string type, name;
	MyArray<std::string> towns;
	double volumeWeid, width, lengt, height;

	std::cout << "������� ������ � ��������: " << std::endl;
	inputData("������� ���: ", type);
	inputData("������� ������������: ", name);
	inputData("������� ����� �����: ", volumeWeid, 0.0, double(INT32_MAX));
	inputData("������� ����� �����: ", lengt, 0.0, double(INT32_MAX));
	inputData("������� ������ �����: ", width, 0.0, double(INT32_MAX));
	inputData("������� ������ �����: ", height, 0.0, double(INT32_MAX));
	inputTowns(towns);

	return Plane(type, name, volumeWeid, width, lengt, height, towns);
}

Car inputCar() {
	int yearRelease;
	std::string mark, model;
	MyArray<CarsTown> towns;

	std::cout << "������� ������ �� ����������: " << std::endl;
	inputData("������� �����: ", mark);
	inputData("������� ������: ", model);
	inputData("������� ��� �������: ", yearRelease, 0, INT32_MAX);
	inputTowns(towns);
	
	return Car(mark, model, yearRelease, towns);
}

Train inputTrain() {
	int yearRelease, countWagons;
	double volumeWeid;
	std::string name;
	MyArray<std::string> route;

	std::cout << "������� ������ � ������: " << std::endl;
	inputData("������� ������������: ", name);
	inputData("������� ����� �����: ", volumeWeid, 0.0, double(INT32_MAX));
	inputData("������� ��� �������: ", yearRelease, 0, INT32_MAX);
	inputData("������� ���������� �������: ", countWagons, 0, INT32_MAX);
	inputTowns(route);
	return Train(name, volumeWeid, yearRelease, countWagons, route);
}

void changePlane(Plane& plane) {
	std::string tmpString = "";
	MyArray<std::string> tmpStringArray;
	double tmpDouble = 0.0;
	bool isExit = false;
	while (!isExit) {

		std::cout << "1. �������� ���" << std::endl;
		std::cout << "2. �������� ������������" << std::endl;
		std::cout << "3. �������� ����� ������������ �����" << std::endl;
		std::cout << "4. �������� ����� �����" << std::endl;
		std::cout << "5. �������� ������ �����" << std::endl;
		std::cout << "6. �������� ������ �����" << std::endl;
		std::cout << "7. �������� ������ �������" << std::endl;
		std::cout << "8. ������� ������ �� �����" << std::endl;
		std::cout << "0. ��������� ���������" << std::endl;
		std::cout << "�������� ����� ����: ";

		int method = processingInput(0, 8);
		switch (method)
		{
		case 1:
			inputData("������� ���: ", tmpString);
			plane.setType(tmpString);
			break;
		case 2:
			inputData("������� ������������: ", tmpString);
			plane.setName(tmpString);
			break;
		case 3:
			inputData("������� ����� ������������ �����: ", tmpDouble, 0.0, double(INT32_MAX));
			plane.setVolumeWeid(tmpDouble);
			break;
		case 4:
			inputData("������� ����� �����: ", tmpDouble, 0.0, double(INT32_MAX));
			plane.setLengt(tmpDouble);
			break;
		case 5:
			inputData("������� ������ �����: ", tmpDouble, 0.0, double(INT32_MAX));
			plane.setWidth(tmpDouble);
			break;
		case 6:
			inputData("������� ������ �����: ", tmpDouble, 0.0, double(INT32_MAX));
			plane.setHeight(tmpDouble);
			break;
		case 7:
			inputTowns(tmpStringArray);
			plane.setTowns(tmpStringArray);
			break;
		case 8:
			plane.print(std::cout);
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void changeCar(Car& car) {
	std::string tmpString = "";
	MyArray<CarsTown> tmpCarTowns;
	int tmpInt = 0;
	bool isExit = false;
	while (!isExit) {

		std::cout << "1. �������� ������" << std::endl;
		std::cout << "2. �������� �����" << std::endl;
		std::cout << "3. �������� ��� �������" << std::endl;
		std::cout << "4. �������� ������ �������" << std::endl;
		std::cout << "5. ������� ������ �� �����" << std::endl;
		std::cout << "0. ��������� ���������" << std::endl;
		std::cout << "�������� ����� ����: ";

		int method = processingInput(0, 4);
		switch (method)
		{
		case 1:
			inputData("������� ������: ", tmpString);
			car.setModel(tmpString);
			break;
		case 2:
			inputData("������� �����: ", tmpString);
			car.setMark(tmpString);
			break;
		case 3:
			inputData("������� ��� �������: ", tmpInt, 0, INT32_MAX);
			car.setYearRelease(tmpInt);
			break;
		case 4:
			inputTowns(tmpCarTowns);
			car.setTowns(tmpCarTowns);
			break;
		case 5:
			car.print(std::cout);
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void changeTrain(Train& train) {
	std::string tmpString = "";
	MyArray<std::string> tmpStringArray;
	double tmpDouble = 0.0;
	int tmpInt = 0;
	bool isExit = false;
	while (!isExit) {

		std::cout << "1. �������� ������������" << std::endl;
		std::cout << "2. �������� ��� �������" << std::endl;
		std::cout << "3. �������� ����� ������������ �����" << std::endl;
		std::cout << "4. �������� ���������� �������" << std::endl;
		std::cout << "5. �������� �������" << std::endl;
		std::cout << "6. ������� ������ �� �����" << std::endl;
		std::cout << "0. ��������� ���������" << std::endl;
		std::cout << "�������� ����� ����: ";

		int method = processingInput(0, 6);
		switch (method)
		{
		case 1:
			inputData("������� ������������: ", tmpString);
			train.setName(tmpString);
			break;
		case 2:
			inputData("������� ��� �������: ", tmpInt, 0, INT32_MAX);
			train.setYearRelease(tmpInt);
			break;
		case 3:
			inputData("������� ����� ������������ �����: ", tmpDouble, 0.0, double(INT32_MAX));
			train.setVolumeWeid(tmpDouble);
			break;
		case 4:
			inputData("������� ��������� �������: ", tmpInt, 0, INT32_MAX);
			train.setCountWagons(tmpInt);
			break;
		case 5:
			inputTowns(tmpStringArray);
			train.setRoute(tmpStringArray);
			break;
		case 6:
			train.print(std::cout);
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void inputTowns(MyArray<std::string>& towns) {
	int countTowns;
	inputData("������� ���������� ������� � ��������: ", countTowns, 0, INT32_MAX);
	for (int i = 0; i < countTowns; i++) {
		std::string townName;
		inputData("������� �������� ������ " + std::to_string(i + 1) + ": ", townName);
		towns.add(townName);
	}
}

void inputTowns(MyArray<CarsTown>& towns) {
	int countTowns;
	inputData("������� ���������� �������: ", countTowns, 0, INT32_MAX);
	for (int i = 0; i < countTowns; i++) {
		std::string townName;
		double volumeWeid, wayHours;
		inputData("������� �������� ������ " + std::to_string(i + 1) + ": ", townName);
		inputData("������� ����� ����� ��� ������ " + std::to_string(i + 1) + ": ", volumeWeid, 0.0, double(INT32_MAX));
		inputData("������� ����� � ���� ��� ������ " + std::to_string(i + 1) + ": ", wayHours, 0.0, double(INT32_MAX));
		towns.add(CarsTown(townName, volumeWeid, wayHours));
	}
}

void inputData(std::string help, std::string& data) {
	std::cout << help;
	getline(std::cin, data);
}