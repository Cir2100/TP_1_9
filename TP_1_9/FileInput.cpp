#include "FileInput.h"

Plane inputPlaneFromFile(std::ifstream& file, std::string& tmpString, int& countLines) {

	std::string type = MY_NULL_STRING, name = MY_NULL_STRING;
	MyArray<std::string> towns;
	double volumeWeid = 0.0, width = 0.0, lengt = 0.0, height = 0.0;

	bool isInputType = false, isInputName = false, isInputTowns = false, isInputVolumeWeid = false, isInputWidth = false,
		isInputLendt = false, isInputHeight = false;

	while (true) {
		if (getline(file, tmpString)) {
			countLines++;
			inputField(tmpString, "Тип", type, isInputType);
			inputField(tmpString, "Наименование", name, isInputName);
			inputField(tmpString, "Объем груза", volumeWeid, isInputVolumeWeid);
			inputField(tmpString, "Максимальная длина груза", lengt, isInputLendt);
			inputField(tmpString, "Максимальная ширина груза", width, isInputWidth);
			inputField(tmpString, "Максимальная высота груза", height, isInputHeight);
			inputTowns(tmpString, "Список городов", towns, isInputTowns, file, countLines);

			if ((isInputType && isInputName && isInputVolumeWeid && isInputLendt && isInputWidth && isInputHeight && isInputTowns) ||
				contains(tmpString, "Автомобиль") || contains(tmpString, "Поезд"))
				break;
		}
		else
			break;
	}
	return Plane(type, name, volumeWeid, width, lengt, height, towns);
}

Car inputCarFromFile(std::ifstream& file, std::string& tmpString, int& countLines) {

	int yearRelease = 0;
	std::string mark = MY_NULL_STRING, model = MY_NULL_STRING;
	MyArray<CarsTown> towns;

	bool isInputYearRelease = false, isInputMark = false, isInputModel = false, isInputTowns = false;

	while (true) {
		if (getline(file, tmpString)) {
			countLines++;
			inputField(tmpString, "Год релиза", yearRelease, isInputYearRelease);
			inputField(tmpString, "Марка", mark, isInputMark);
			inputField(tmpString, "Модель", model, isInputModel);
			inputTowns(tmpString, "Список городов", towns, isInputTowns, file, countLines);

			if ((isInputYearRelease && isInputMark && isInputModel && isInputTowns) ||
				contains(tmpString, "Самолет") || contains(tmpString, "Поезд"))
				break;
		}
		else
			break;
	}
	return Car(mark, model, yearRelease, towns);
}

Train inputTrainFromFile(std::ifstream& file, std::string& tmpString, int& countLines) {

	int yearRelease = 0, countWagons = 0;
	double volumeWeid = 0.0;
	std::string name = MY_NULL_STRING;
	MyArray<std::string> route;

	bool isInputYearRelease = false, isInputCountWagons = false, isInputRoute = false,
		isInputVolumeWeid = false, isInputName = false;

	while (true) {
		if (getline(file, tmpString)) {
			countLines++;
			inputField(tmpString, "Год релиза", yearRelease, isInputYearRelease);
			inputField(tmpString, "Количчество вагонов", countWagons, isInputCountWagons);
			inputField(tmpString, "Объем груза", volumeWeid, isInputVolumeWeid);
			inputField(tmpString, "Наименование", name, isInputName);
			inputTowns(tmpString, "Маршрут поезда", route, isInputRoute, file, countLines);

			if ((isInputYearRelease && isInputCountWagons && isInputVolumeWeid && isInputName && isInputRoute) ||
				contains(tmpString, "Автомобиль") || contains(tmpString, "Самолет"))
				break;
		}
		else
			break;
	}

	return Train(name, volumeWeid, yearRelease, countWagons, route);
}

void checkInput(const std::string& input, std::string& field) {
	field = input;
}

void checkInput(const std::string& input, int& field) {
	bool sign = false, err = false;
	int result = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
			result = result * 10 + (input[i] - '0');
		else if (i == 0 && input[i] == '-')
			sign = true;
		else
			err = true;
	}

	if (sign)
		result = -result;

	if (!err)
		field = result;
	else
		field = 0;
}

void checkInput(const std::string& input, double& field) {
	bool sign = false, flpoint = false, err = false;
	double result = 0, d = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			if (flpoint) {
				result += (input[i] - '0') * d;
				d /= 10;
			}
			else
				result = result * 10 + (input[i] - '0');
		}
		else if (i == 0 && input[i] == '-')
			sign = true;
		else if (i != 0 && input[i] == '.') {
			flpoint = true;
			d = 0.1;
		}
		else
			err = true;
	}

	if (sign)
		result = -result;

	if (!err)
		field = result;
	else
		field = 0.0;
}

bool contains(const std::string& str, const std::string& substr) {
	return (str.find(substr) != std::string::npos);
}

template <typename T>
void inputField(std::string& input, const std::string& nameField, T& field, bool& isInputField) {
	if (contains(input, nameField) && !isInputField) {
		input = input.substr(input.find_last_of("=") + 2);
		checkInput(input, field);
		isInputField = true;
	}
}

void inputTowns(std::string& input, const std::string& nameField, MyArray<std::string>& towns, 
	bool& isInputField, std::ifstream& file, int& countLines) {
	if (contains(input, nameField) && !isInputField) {
		isInputField = true;
		while (true) {
			if (getline(file, input)) {
				countLines++;
				if (!contains(input, "Название города"))
					break;
				else {
					bool tmp = false;
					inputField(input, "Название города", input, tmp);
					towns.add(input);
				}
			}
			else
				break;
		}
	}
}

void inputTowns(std::string& input, const std::string& nameField, MyArray<CarsTown>& towns, 
	bool& isInputField, std::ifstream& file, int& countLines) {
	if (contains(input, nameField) && !isInputField) {
		isInputField = true;
		bool stopInput = false;
		while (true) {

			bool isInputName = false, isInputWayHours = false, isInputVolumeWeid = false;
			std::string name = MY_NULL_STRING;
			double volumeWeid = 0.0, wayHours = 0.0;
			for (int i = 0; i < 3; i++) {
				if (getline(file, input)) {
					countLines++;
					if (contains(input, "Название города") ||
						contains(input, "Время в пути") ||
						contains(input, "Объем груза")) {
						inputField(input, "Название города", name, isInputName);
						inputField(input, "Время в пути", wayHours, isInputWayHours);
						inputField(input, "Объем груза", volumeWeid, isInputVolumeWeid);

						if (isInputName && isInputWayHours && isInputVolumeWeid)
							break;
					}
					else {
						stopInput = true;
						break;
					}
				}
				else {
					stopInput = true;
					break;
				}
			}
			if (isInputName || isInputWayHours || isInputVolumeWeid) {
				CarsTown town(name, volumeWeid, wayHours);
				towns.add(town);
			}
			if (stopInput)
				break;
		}
	}
}