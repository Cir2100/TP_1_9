#include "Train.h"

Train::Train(std::string _name, double _volumeWeid, int _yearRelease, int _countWagons, MyArray<std::string> _towns)
	: Base(TRAIN_STRING), name(_name), volumeWeid(_volumeWeid), yearRelease(_yearRelease),
	countWagons(_countWagons), towns(_towns)
	{ Logger::printBuilder("Train"); }

Train::Train(const Train& train)
	: Base(train), name(train.name), volumeWeid(train.volumeWeid), yearRelease(train.yearRelease),
	countWagons(train.countWagons), towns(train.towns)
	{ Logger::printCopyBuilder("Train"); }

void Train::inputFromConsole() {
	std::cout << "������� ������ � ������: " << std::endl;
	inputData("������� ������������: ", name);
	inputData("������� ����� �����: ", volumeWeid, 0.0, double(INT32_MAX));
	inputData("������� ��� �������: ", yearRelease, 0, INT32_MAX);
	inputData("������� ���������� �������: ", countWagons, 0, INT32_MAX);
	inputTownsFromConsole();
}

void Train::inputFromFile(std::ifstream& file, std::string& tmpString, int& countLines) {

	MyArray<std::string> unrecognizedStrings;

	bool isInputYearRelease = false, isInputCountWagons = false, isInputTowns = false,
		isInputVolumeWeid = false, isInputName = false;

	while (true) {
		if (getline(file, tmpString)) {
			countLines++;
			bool isInput = false;
			try {
				inputField(tmpString, YEAR_RELISE_STRING, yearRelease, isInputYearRelease, isInput);
				inputField(tmpString, COUNT_WAGONS_STRING, countWagons, isInputCountWagons, isInput);
				inputField(tmpString, VOLUME_WEID_STRING, volumeWeid, isInputVolumeWeid, isInput);
				inputField(tmpString, NAME_STRING, name, isInputName, isInput);
				inputTownsFromFile(tmpString, TOWN_LIST_STRING, isInputTowns, file, countLines, isInput);
			}
			catch (int resultCode) {
				if (resultCode == -1) {
					int countLinesStart = countLines;
					while (true) {
						if (getline(file, tmpString)) {
							countLines++;
							if (contains(tmpString, CAR_STRING) || contains(tmpString, PLANE_STRING))
								break;
						}
						else
							break;
					}
					Logger::printWarning("�� ������ " + std::to_string(countLinesStart) + " �� ������ " + std::to_string(countLines)
						+ " ������ �� ����� ���� �������");
					break;
				}
			}

			if ((isInputYearRelease && isInputCountWagons && isInputVolumeWeid && isInputName && isInputTowns) ||
				contains(tmpString, CAR_STRING) || contains(tmpString, PLANE_STRING))
				break;
			if (!isInput) {
				Logger::printWarning("������ � ������ " + std::to_string(countLines) + " �� ����������");
				unrecognizedStrings.add(tmpString);
			}
		}
		else
			break;
	}

	
}

void Train::print(std::ostream& out, std::string number, std::string splitter) {
	Base::print(out, number);
	out << NAME_STRING << " =" << splitter << name << std::endl;
	out << VOLUME_WEID_STRING << " =" << splitter << volumeWeid << std::endl;
	out << YEAR_RELISE_STRING << " =" << splitter << yearRelease << std::endl;
	out << COUNT_WAGONS_STRING << " =" << splitter << countWagons << std::endl;
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

void Train::change() {
	std::string tmpString = "";
	double tmpDouble = 0.0;
	int tmpInt = 0;
	bool isExit = false;
	while (!isExit) {

		std::cout << "1. �������� ������������" << std::endl;
		std::cout << "2. �������� ��� �������" << std::endl;
		std::cout << "3. �������� ����� ������������ �����" << std::endl;
		std::cout << "4. �������� ���������� �������" << std::endl;
		std::cout << "5. �������� �������" << std::endl;
		std::cout << "6. ������� �������������� ������" << std::endl;
		std::cout << "7. ������� ������ �� �����" << std::endl;
		std::cout << "0. ��������� ���������" << std::endl;
		std::cout << "�������� ����� ����: ";

		int method = processingInput(0, 7);
		switch (method)
		{
		case 1:
			inputData("������� ������������: ", tmpString);
			setName(tmpString);
			break;
		case 2:
			inputData("������� ��� �������: ", tmpInt, 0, INT32_MAX);
			setYearRelease(tmpInt);
			break;
		case 3:
			inputData("������� ����� ������������ �����: ", tmpDouble, 0.0, double(INT32_MAX));
			setVolumeWeid(tmpDouble);
			break;
		case 4:
			inputData("������� ��������� �������: ", tmpInt, 0, INT32_MAX);
			setCountWagons(tmpInt);
			break;
		case 5:
			towns.clear();
			inputTownsFromConsole();
			break;
		case 6:
			if (unrecognizedStrings.getSize() > 0) {
				unrecognizedStrings.clear();
				Logger::printMessage("�������������� ������ ������� �������");
			}
			else
				Logger::printMessage("�������������� ������ ��� �����");
			break;
		case 7:
			print(std::cout);
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

MyArray<std::string> Train::toStringArray(std::string number) {
	MyArray<std::string> strings = Base::toStringArray(number);
	strings.add(NAME_STRING + " = " + name + "\n");
	strings.add(VOLUME_WEID_STRING + " = " + std::to_string(volumeWeid) + "\n");
	strings.add(YEAR_RELISE_STRING + " = " + std::to_string(yearRelease) + "\n");
	strings.add(COUNT_WAGONS_STRING + " = " + std::to_string(countWagons) + "\n");
	if (towns.getSize() > 0) {
		strings.add(TOWN_LIST_STRING + "\n");
		for (int i = 0; i < towns.getSize(); i++)
			strings.add(TOWN_NAME_STRING + std::to_string(i + 1) + " = " + towns[i] + "\n");
	}
	else
		strings.add(EMPTY_TOWN_LIST_STRING + "\n");
	return strings;
}

Train& Train::operator=(const Train& train)
{
	if (this == &train)
		return *this;
	name = train.name;
	volumeWeid = train.volumeWeid;
	yearRelease = train.yearRelease;
	countWagons = train.countWagons;
	towns = train.towns;
	unrecognizedStrings = train.unrecognizedStrings;
	return *this;
}

void Train::inputTownsFromConsole() {
	int countTowns;
	inputData("������� ���������� ������� � ��������: ", countTowns, 0, INT32_MAX);
	for (int i = 0; i < countTowns; i++) {
		std::string townName;
		inputData("������� �������� ������ " + std::to_string(i + 1) + ": ", townName);
		towns.add(townName);
	}
}

void Train::inputTownsFromFile(std::string& input, const std::string& nameField,
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