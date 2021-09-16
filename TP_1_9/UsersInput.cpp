#include "UsersInput.h"


int chouseStream() {
	std::cout << "1. Файл" << std::endl;
	std::cout << "2. Консоль" << std::endl;
	std::cout << "0. Отмена" << std::endl;
	return processingInput(0, 2);
}

int chouseObject() {
	std::cout << "1. Самолет" << std::endl;
	std::cout << "2. Автомобиль" << std::endl;
	std::cout << "3. Поезд" << std::endl;
	std::cout << "0. Отмена" << std::endl;
	return processingInput(0, 3);
}

//получение имени входного файлa
//ввод 0 означает отказ от ввода данных из файла.
bool processInputNameOfInputFile(std::ifstream& file)
{
	//получение названия файла
	std::string filename;
	bool isCorrect;
	std::cout << "Введите название файла (с расширением): ";
	std::cin >> filename;
	isCorrect = checkFilename(filename);
	if (isCorrect)
		file.open(filename);
	while (!file.is_open() && filename[0] != '0')
	{
		if (isCorrect)
			std::cout << "Такого файла не существует." << std::endl;
		std::cout << "Введите название повторно (с расширением): ";
		std::cin >> filename;
		isCorrect = checkFilename(filename);
		if (isCorrect)
			file.open(filename);
	}
	if (filename[0] != '0') {
		std::cout << "Файл успешно открыт" << std::endl;
		return true;
	}
	else {
		std::cout << "Вы отказались от ввода данных из файла" << std::endl;
		return false;
	}
		
}
//получение имени выходного файлa
//ввод 0 означает отказ от ввода данных из файла.
std::string processInputNameOfOutputFile()
{
	//получение названия файла
	std::string filename;
	bool isCorrect;
	std::cout << "Введите название файла (с расширением): ";
	std::cin >> filename;
	isCorrect = checkFilename(filename);
	while (!isCorrect) {
		std::cin >> filename;
		isCorrect = checkFilename(filename);
	}
	return filename;
}
//проверка корректности имени файла
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
		std::cout << "Данное имя файла используется Windows." << std::endl;
		return false;
	}
	int i = file.size();
	if ((file[i] == '\0') && (file[i - 1] == 't') && (file[i - 2] == 'x') && (file[i - 3] == 't') && (file[i - 4] == '.'))
		return true;
	else
	{
		if (file[i - 1] != '0')
			std::cout << "Файл должен иметь формат .txt" << std::endl;
		return false;
	}
}

Plane inputPlane() {
	std::string type, name;
	MyArray<std::string> towns;
	double volumeWeid, width, lengt, height;

	std::cout << "Введите данные о самолете: " << std::endl;
	inputData("Введите тип: ", type);
	inputData("Введите наименование: ", name);
	inputData("Введите объем груза: ", volumeWeid, 0.0, double(INT32_MAX));
	inputData("Введите длину груза: ", lengt, 0.0, double(INT32_MAX));
	inputData("Введите ширину груза: ", width, 0.0, double(INT32_MAX));
	inputData("Введите высоту груза: ", height, 0.0, double(INT32_MAX));
	inputTowns(towns);

	return Plane(type, name, volumeWeid, width, lengt, height, towns);
}

Car inputCar() {
	int yearRelease;
	std::string mark, model;
	MyArray<CarsTown> towns;

	std::cout << "Введите данные об автомобиле: " << std::endl;
	inputData("Введите марку: ", mark);
	inputData("Введите модель: ", model);
	inputData("Введите год выпуска: ", yearRelease, 0, INT32_MAX);
	inputTowns(towns);
	
	return Car(mark, model, yearRelease, towns);
}

Train inputTrain() {
	int yearRelease, countWagons;
	double volumeWeid;
	std::string name;
	MyArray<std::string> route;

	std::cout << "Введите данные о поезде: " << std::endl;
	inputData("Введите наименование: ", name);
	inputData("Введите объем груза: ", volumeWeid, 0.0, double(INT32_MAX));
	inputData("Введите год выпуска: ", yearRelease, 0, INT32_MAX);
	inputData("Введите количество вагонов: ", countWagons, 0, INT32_MAX);
	inputTowns(route);
	return Train(name, volumeWeid, yearRelease, countWagons, route);
}

void changePlane(Plane& plane) {
	std::string tmpString = "";
	MyArray<std::string> tmpStringArray;
	double tmpDouble = 0.0;
	bool isExit = false;
	while (!isExit) {

		std::cout << "1. Изменить тип" << std::endl;
		std::cout << "2. Изменить наименование" << std::endl;
		std::cout << "3. Изменить объем перевозимого груза" << std::endl;
		std::cout << "4. Изменить длину груза" << std::endl;
		std::cout << "5. Изменить ширину груза" << std::endl;
		std::cout << "6. Изменить высоту груза" << std::endl;
		std::cout << "7. Изменить список городов" << std::endl;
		std::cout << "8. Вывести данные на экран" << std::endl;
		std::cout << "0. Сохранить изменения" << std::endl;
		std::cout << "Выберете пункт меню: ";

		int method = processingInput(0, 8);
		switch (method)
		{
		case 1:
			inputData("Введите тип: ", tmpString);
			plane.setType(tmpString);
			break;
		case 2:
			inputData("Введите наименование: ", tmpString);
			plane.setName(tmpString);
			break;
		case 3:
			inputData("Введите объем перевозимого груза: ", tmpDouble, 0.0, double(INT32_MAX));
			plane.setVolumeWeid(tmpDouble);
			break;
		case 4:
			inputData("Введите длину груза: ", tmpDouble, 0.0, double(INT32_MAX));
			plane.setLengt(tmpDouble);
			break;
		case 5:
			inputData("Введите ширину груза: ", tmpDouble, 0.0, double(INT32_MAX));
			plane.setWidth(tmpDouble);
			break;
		case 6:
			inputData("Введите высоту груза: ", tmpDouble, 0.0, double(INT32_MAX));
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

		std::cout << "1. Изменить модель" << std::endl;
		std::cout << "2. Изменить марку" << std::endl;
		std::cout << "3. Изменить год выпуска" << std::endl;
		std::cout << "4. Изменить список городов" << std::endl;
		std::cout << "5. Вывести данные на экран" << std::endl;
		std::cout << "0. Сохранить изменения" << std::endl;
		std::cout << "Выберете пункт меню: ";

		int method = processingInput(0, 4);
		switch (method)
		{
		case 1:
			inputData("Введите модель: ", tmpString);
			car.setModel(tmpString);
			break;
		case 2:
			inputData("Введите марку: ", tmpString);
			car.setMark(tmpString);
			break;
		case 3:
			inputData("Введите год выпуска: ", tmpInt, 0, INT32_MAX);
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

		std::cout << "1. Изменить наименование" << std::endl;
		std::cout << "2. Изменить год выпуска" << std::endl;
		std::cout << "3. Изменить объем перевозимого груза" << std::endl;
		std::cout << "4. Изменить количество вагонов" << std::endl;
		std::cout << "5. Изменить маршрут" << std::endl;
		std::cout << "6. Вывести данные на экран" << std::endl;
		std::cout << "0. Сохранить изменения" << std::endl;
		std::cout << "Выберете пункт меню: ";

		int method = processingInput(0, 6);
		switch (method)
		{
		case 1:
			inputData("Введите наименование: ", tmpString);
			train.setName(tmpString);
			break;
		case 2:
			inputData("Введите год выпуска: ", tmpInt, 0, INT32_MAX);
			train.setYearRelease(tmpInt);
			break;
		case 3:
			inputData("Введите объем перевозимого груза: ", tmpDouble, 0.0, double(INT32_MAX));
			train.setVolumeWeid(tmpDouble);
			break;
		case 4:
			inputData("Введите количство вагонов: ", tmpInt, 0, INT32_MAX);
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
	inputData("Введите количество городов в маршруте: ", countTowns, 0, INT32_MAX);
	for (int i = 0; i < countTowns; i++) {
		std::string townName;
		inputData("Введите название города " + std::to_string(i + 1) + ": ", townName);
		towns.add(townName);
	}
}

void inputTowns(MyArray<CarsTown>& towns) {
	int countTowns;
	inputData("Введите количество городов: ", countTowns, 0, INT32_MAX);
	for (int i = 0; i < countTowns; i++) {
		std::string townName;
		double volumeWeid, wayHours;
		inputData("Введите название города " + std::to_string(i + 1) + ": ", townName);
		inputData("Введите объем груза для города " + std::to_string(i + 1) + ": ", volumeWeid, 0.0, double(INT32_MAX));
		inputData("Введите время в пути для города " + std::to_string(i + 1) + ": ", wayHours, 0.0, double(INT32_MAX));
		towns.add(CarsTown(townName, volumeWeid, wayHours));
	}
}

void inputData(std::string help, std::string& data) {
	std::cout << help;
	getline(std::cin, data);
}