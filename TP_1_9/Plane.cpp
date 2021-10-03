#include "Plane.h"

Plane::Plane(std::string _type, std::string _name, double _volumeWeid, double _width,
	double _lengt, double _height, MyArray<std::string> _towns)
	:Base(PLANE_STRING), type(_type), name(_name), volumeWeid(_volumeWeid), width(_width),
	lengt(_lengt), height(_height), towns(_towns) 
	{ Logger::printBuilder("Plane"); }

Plane::Plane(const Plane& plane) :
	type(plane.type), name(plane.name), volumeWeid(plane.volumeWeid), width(plane.width),
	lengt(plane.lengt), height(plane.height), towns(plane.towns)
	{ Logger::printCopyBuilder("Plane"); }

void Plane::inputFromConsole() {
	std::cout << "Введите данные о самолете: " << std::endl;
	inputData("Введите тип: ", type);
	inputData("Введите наименование: ", name);
	inputData("Введите объем груза: ", volumeWeid, 0.0, double(INT32_MAX));
	inputData("Введите длину груза: ", lengt, 0.0, double(INT32_MAX));
	inputData("Введите ширину груза: ", width, 0.0, double(INT32_MAX));
	inputData("Введите высоту груза: ", height, 0.0, double(INT32_MAX));
	inputTownsFromConsole();
}

void Plane::inputFromFile(std::ifstream& file, std::string& tmpString, int& countLines) {

	bool isInputType = false, isInputName = false, isInputTowns = false, isInputVolumeWeid = false, isInputWidth = false,
		isInputLendt = false, isInputHeight = false;

	while (true) {
		if (getline(file, tmpString)) {
			countLines++;
			bool isInput = false;
			try {
				inputField(tmpString, TYPE_STRING, type, isInputType, isInput);
				inputField(tmpString, NAME_STRING, name, isInputName, isInput);
				inputField(tmpString, VOLUME_WEID_STRING, volumeWeid, isInputVolumeWeid, isInput);
				inputField(tmpString, MAX_LENGT_STRING, lengt, isInputLendt, isInput);
				inputField(tmpString, MAX_WIDTH_STRING, width, isInputWidth, isInput);
				inputField(tmpString, MAX_HEIGHT_STRING, height, isInputHeight, isInput);
				inputTownsFromFile(tmpString, TOWN_LIST_STRING, isInputTowns, file, countLines, isInput);
			}
			catch (int resultCode) {
				if (resultCode == -1) {
					int countLinesStart = countLines;
					while (true) {
						if (getline(file, tmpString)) {
							countLines++;
							if (contains(tmpString, CAR_STRING) || contains(tmpString, TRAIN_STRING))
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

			if ((isInputType && isInputName && isInputVolumeWeid && isInputLendt && isInputWidth && isInputHeight && isInputTowns) ||
				contains(tmpString, CAR_STRING) || contains(tmpString, TRAIN_STRING))
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

void Plane::print(std::ostream& out, std::string number, std::string splitter) {
	Base::print(out, number);
	out << TYPE_STRING << " =" << splitter << type << std::endl;
	out << NAME_STRING << " =" << splitter << name << std::endl;
	out << VOLUME_WEID_STRING << " =" << splitter << volumeWeid << std::endl;
	out << MAX_LENGT_STRING << " =" << splitter << lengt << std::endl;
	out << MAX_WIDTH_STRING << " =" << splitter << width << std::endl;
	out << MAX_HEIGHT_STRING << " =" << splitter << height << std::endl;
	if (towns.getSize() > 0) {
		out << TOWN_LIST_STRING << std::endl;
		for (int i = 0; i < towns.getSize(); i++)
			out << TOWN_NAME_STRING << i + 1 << " =" << splitter << towns[i] << std::endl;
	}
	else
		out << EMPTY_TOWN_LIST_STRING << std::endl;
	Base::printUnrecognizedStrings(out);
	out << std::endl;
}

void Plane::change() {
	std::string tmpString = "";
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
		std::cout << "8. Удалить нераспознаныне строки" << std::endl;
		std::cout << "9. Вывести данные на экран" << std::endl;
		std::cout << "0. Сохранить изменения" << std::endl;
		std::cout << "Выберете пункт меню: ";

		int method = processingInput(0, 9);
		switch (method)
		{
		case 1:
			inputData("Введите тип: ", tmpString);
			setType(tmpString);
			break;
		case 2:
			inputData("Введите наименование: ", tmpString);
			setName(tmpString);
			break;
		case 3:
			inputData("Введите объем перевозимого груза: ", tmpDouble, 0.0, double(INT32_MAX));
			setVolumeWeid(tmpDouble);
			break;
		case 4:
			inputData("Введите длину груза: ", tmpDouble, 0.0, double(INT32_MAX));
			setLengt(tmpDouble);
			break;
		case 5:
			inputData("Введите ширину груза: ", tmpDouble, 0.0, double(INT32_MAX));
			setWidth(tmpDouble);
			break;
		case 6:
			inputData("Введите высоту груза: ", tmpDouble, 0.0, double(INT32_MAX));
			setHeight(tmpDouble);
			break;
		case 7:
			towns.clear();
			inputTownsFromConsole();
			break;
		case 8:
			unrecognizedStrings.clear();
			break;
		case 9:
			print(std::cout);
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

MyArray<std::string> Plane::toStringArray(std::string number) {
	MyArray<std::string> strings = Base::toStringArray(number);
	strings.add(TYPE_STRING + " = " + type + "\n");
	strings.add(NAME_STRING + " = " + name + "\n");
	strings.add(VOLUME_WEID_STRING + " = " + std::to_string(volumeWeid) + "\n");
	strings.add(MAX_LENGT_STRING + " = " + std::to_string(lengt) + "\n");
	strings.add(MAX_WIDTH_STRING + " = " + std::to_string(width) + "\n");
	strings.add(MAX_HEIGHT_STRING + " = " + std::to_string(height) + "\n");
	if (towns.getSize() > 0) {
		strings.add(TOWN_LIST_STRING + "\n");
		for (int i = 0; i < towns.getSize(); i++)
			strings.add(TOWN_NAME_STRING + std::to_string(i + 1) + " = " + towns[i] + "\n");
	}
	else
		strings.add(EMPTY_TOWN_LIST_STRING + "\n");
	return strings;
}

Plane& Plane::operator=(const Plane& plane)
{
	if (this == &plane)
		return *this;
	type = plane.type;
	name = plane.name;
	volumeWeid = plane.volumeWeid;
	width = plane.width;
	lengt = plane.lengt;
	height = plane.height;
	towns = plane.towns;
	unrecognizedStrings = plane.unrecognizedStrings;
	return *this;
}

void Plane::inputTownsFromConsole() {
	int countTowns;
	inputData("Введите количество городов в маршруте: ", countTowns, 0, INT32_MAX);
	for (int i = 0; i < countTowns; i++) {
		std::string townName;
		inputData("Введите название города " + std::to_string(i + 1) + ": ", townName);
		towns.add(townName);
	}
}

void Plane::inputTownsFromFile(std::string& input, const std::string& nameField,
	bool& isInputField, std::ifstream& file, int& countLines, bool& isInput) {
	if (contains(input, nameField) && !isInputField) {
		isInputField = true;
		isInput = true;
		while (true) {
			if (getline(file, input)) {
				countLines++;
				if (!contains(input, TOWN_NAME_STRING))
					break;
				else {
					bool tmp = false;
					inputField(input, TOWN_NAME_STRING, input, tmp, tmp);
					if (!tmp)
						unrecognizedStrings.add(input);
					else
						towns.add(input);
				}
			}
			else
				break;
		}
	}
}
