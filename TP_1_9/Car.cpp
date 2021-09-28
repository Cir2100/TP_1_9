#include "Car.h"

Car::Car(std::string _mark, std::string _model, int _yearRelease, MyArray<CarsTown> _towns)
	: Base(CAR_STRING), mark(_mark), model(_model), yearRelease(_yearRelease), towns(_towns)
	{ Logger::printBuilder("Car"); }

Car::Car(const Car& car)
	: mark(car.mark), model(car.model), yearRelease(car.yearRelease), towns(car.towns)
	{ Logger::printCopyBuilder("Car"); }

void Car::inputFromConsole() {
	std::cout << "Введите данные об автомобиле: " << std::endl;
	inputData("Введите марку: ", mark);
	inputData("Введите модель: ", model);
	inputData("Введите год выпуска: ", yearRelease, 0, INT32_MAX);
	inputTownsFromConsole();
}

void Car::inputFromFile(std::ifstream& file, std::string& tmpString, int& countLines) {

	bool isInputYearRelease = false, isInputMark = false, isInputModel = false, isInputTowns = false;

	while (true) {
		if (getline(file, tmpString)) {
			countLines++;
			bool isInput = false;
			try {
				inputField(tmpString, YEAR_RELISE_STRING, yearRelease, isInputYearRelease, isInput);
				inputField(tmpString, MARK_STRING, mark, isInputMark, isInput);
				inputField(tmpString, MODEL_STRING, model, isInputModel, isInput);
				inputTownsFromFile(tmpString, TOWN_LIST_STRING, isInputTowns, file, countLines, isInput);
			}
			catch (int resultCode) {
				if (resultCode == -1) {
					int countLinesStart = countLines;
					while (true) {
						if (getline(file, tmpString)) {
							countLines++;
							if (contains(tmpString, PLANE_STRING) || contains(tmpString, TRAIN_STRING))
								break;
						}
						else
							break;
					}
					Logger::printWarning("Со строки " + std::to_string(countLinesStart) + " до строки " + std::to_string(countLines)
						+ " данные не могут быть считаны");
					break;
				}
			}

			if ((isInputYearRelease && isInputMark && isInputModel && isInputTowns) ||
				contains(tmpString, PLANE_STRING) || contains(tmpString, TRAIN_STRING))
				break;
			if (!isInput) {
				Logger::printWarning("Данные в строке " + std::to_string(countLines) + " не распознаны");
				unrecognizedStrings.add(tmpString);
			}		
		}
		else
			break;
	}
	
}

void Car::print(std::ostream& out, std::string number, std::string splitter) {
	Base::print(out, number);
	out << MARK_STRING << " =" << splitter << mark << std::endl;
	out << MODEL_STRING << " =" << splitter << model << std::endl;
	out << YEAR_RELISE_STRING << " =" << splitter << yearRelease << std::endl;
	if (towns.getSize() > 0) {
		out << TOWN_LIST_STRING << std::endl;
		for (int i = 0; i < towns.getSize(); i++)
			towns[i].print(out, std::to_string(i + 1), splitter);
	}
	else
		out << EMPTY_TOWN_LIST_STRING << std::endl;
	Base::printUnrecognizedStrings(out);
	out << std::endl;
}

void Car::change() {
	std::string tmpString = MY_NULL_STRING;
	int tmpInt = 0;
	bool isExit = false;
	while (!isExit) {

		std::cout << "1. Изменить модель" << std::endl;
		std::cout << "2. Изменить марку" << std::endl;
		std::cout << "3. Изменить год выпуска" << std::endl;
		std::cout << "4. Изменить список городов" << std::endl;
		std::cout << "5. Вывести данные на экран" << std::endl;
		std::cout << "6. Удалить нераспознаныне строки" << std::endl;
		std::cout << "0. Сохранить изменения" << std::endl;
		std::cout << "Выберете пункт меню: ";

		int method = processingInput(0, 6);
		switch (method)
		{
		case 1:
			inputData("Введите модель: ", tmpString);
			setModel(tmpString);
			break;
		case 2:
			inputData("Введите марку: ", tmpString);
			setMark(tmpString);
			break;
		case 3:
			inputData("Введите год выпуска: ", tmpInt, 0, INT32_MAX);
			setYearRelease(tmpInt);
			break;
		case 4:
			towns.clear();
			inputTownsFromConsole();
			break;
		case 5:
			print(std::cout);
			break;
		case 6:
			unrecognizedStrings.clear();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

Car& Car::operator=(const Car& car)
{
	if (this == &car)
		return *this;
	yearRelease = car.yearRelease;
	mark = car.mark;
	model = car.model;
	towns = car.towns;
	unrecognizedStrings = car.unrecognizedStrings;
	return *this;
}

void Car::inputTownsFromConsole() {
	int countTowns;
	inputData("Введите количество городов: ", countTowns, 0, INT32_MAX);
	for (int i = 0; i < countTowns; i++) {
		CarsTown carsTown;
		carsTown.inputFromConsole(i + 1);
		towns.add(carsTown);
	}
}

void Car::inputTownsFromFile(std::string& input, const std::string& nameField,
	bool& isInputField, std::ifstream& file, int& countLines, bool& isInput) {
	if (contains(input, nameField) && !isInputField) {
		isInputField = true;
		isInput = true;
		bool stopInput = false;
		while (true) {
			CarsTown town;
			bool isInputName = false, isInputWayHours = false, isInputVolumeWeid = false;
			town.inputFromFile(input, file, countLines, unrecognizedStrings, stopInput, isInputName, isInputWayHours, isInputVolumeWeid);
			if (isInputName || isInputWayHours || isInputVolumeWeid) {
				towns.add(town);
			}
			if (stopInput)
				break;
		}
	}
}