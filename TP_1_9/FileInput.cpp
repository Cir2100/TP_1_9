#include "FileInput.h"

void inputFromFile(Transporter& transporter, std::ifstream& file) {
	std::string tmpString;
	int countLines = 0;
	bool isInput = false;
	while (true) {
		if (!isInput) {
			if (std::getline(file, tmpString))
				countLines++;
			else
				break;
		}

		if (contains(tmpString, PLANE_STRING)) {
			isInput = true;
			Plane plane = inputPlaneFromFile(file, tmpString, countLines);
			transporter.addObject(plane);
		}
		else if (contains(tmpString, CAR_STRING)) {
			isInput = true;
			Car car = inputCarFromFile(file, tmpString, countLines);
			transporter.addObject(car);
		}
		else if (contains(tmpString, TRAIN_STRING)) {
			isInput = true;
			Train train = inputTrainFromFile(file, tmpString, countLines);
			transporter.addObject(train);
		}
		else
			isInput = false;
	}
}

Plane inputPlaneFromFile(std::ifstream& file, std::string& tmpString, int& countLines) {

	std::string type = MY_NULL_STRING, name = MY_NULL_STRING;
	MyArray<std::string> towns;
	double volumeWeid = 0.0, width = 0.0, lengt = 0.0, height = 0.0;
	MyArray<std::string> unrecognizedStrings;

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
				inputTowns(tmpString, TOWN_LIST_STRING, towns, isInputTowns, file, countLines, unrecognizedStrings, isInput);
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
					Logger::printWarning("—о строки " + std::to_string(countLinesStart) + " до строки " + std::to_string(countLines)
						+ " данные не могут быть считаны");
					break;
				}
			}

			if ((isInputType && isInputName && isInputVolumeWeid && isInputLendt && isInputWidth && isInputHeight && isInputTowns) ||
				contains(tmpString, CAR_STRING) || contains(tmpString, TRAIN_STRING))
				break;
			if (!isInput)
					unrecognizedStrings.add(tmpString);
		}
		else
			break;
	}
	//use unrecognizedStrings
	return Plane(type, name, volumeWeid, width, lengt, height, towns);
}

Car inputCarFromFile(std::ifstream& file, std::string& tmpString, int& countLines) {

	int yearRelease = 0;
	std::string mark = MY_NULL_STRING, model = MY_NULL_STRING;
	MyArray<CarsTown> towns;
	MyArray<std::string> unrecognizedStrings;

	bool isInputYearRelease = false, isInputMark = false, isInputModel = false, isInputTowns = false;

	while (true) {
		if (getline(file, tmpString)) {
			countLines++;
			bool isInput = false;
			try {
				inputField(tmpString, YEAR_RELISE_STRING, yearRelease, isInputYearRelease, isInput);
				inputField(tmpString, MARK_STRING, mark, isInputMark, isInput);
				inputField(tmpString, MODEL_STRING, model, isInputModel, isInput);
				inputTowns(tmpString, TOWN_LIST_STRING, towns, isInputTowns, file, countLines, unrecognizedStrings, isInput);
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
					Logger::printWarning("—о строки " + std::to_string(countLinesStart) + " до строки " + std::to_string(countLines)
						+ " данные не могут быть считаны");
					break;
				}
			}

			if ((isInputYearRelease && isInputMark && isInputModel && isInputTowns) ||
				contains(tmpString, PLANE_STRING) || contains(tmpString, TRAIN_STRING))
				break;
			if (!isInput)
				unrecognizedStrings.add(tmpString);
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
	MyArray<std::string> unrecognizedStrings;

	bool isInputYearRelease = false, isInputCountWagons = false, isInputRoute = false,
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
				inputTowns(tmpString, TOWN_LIST_STRING, route, isInputRoute, file, countLines, unrecognizedStrings, isInput);
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
					Logger::printWarning("—о строки " + std::to_string(countLinesStart) + " до строки " + std::to_string(countLines)
						+ " данные не могут быть считаны");
					break;
				}
			}

			if ((isInputYearRelease && isInputCountWagons && isInputVolumeWeid && isInputName && isInputRoute) ||
				contains(tmpString, CAR_STRING) || contains(tmpString, PLANE_STRING))
				break;
			if (!isInput)
				unrecognizedStrings.add(tmpString);
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
void inputField(std::string& input, const std::string& nameField, T& field, bool& isInputField, bool& isInput) {
	if (contains(input, nameField)) {
		if (!isInputField) {
			input = input.substr(input.find_last_of("=") + 2);
			checkInput(input, field);
			isInputField = true;
			isInput = true;
		}
		else
			throw -1;
	}
}

void inputTowns(std::string& input, const std::string& nameField, MyArray<std::string>& towns, 
	bool& isInputField, std::ifstream& file, int& countLines, MyArray<std::string>& unrecognizedStrings, bool& isInput) {
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

void inputTowns(std::string& input, const std::string& nameField, MyArray<CarsTown>& towns, 
	bool& isInputField, std::ifstream& file, int& countLines, MyArray<std::string>& unrecognizedStrings, bool& isInput) {
	if (contains(input, nameField) && !isInputField) {
		isInputField = true;
		isInput = true;
		bool stopInput = false;
		while (true) {

			bool isInputName = false, isInputWayHours = false, isInputVolumeWeid = false;
			std::string name = MY_NULL_STRING;
			double volumeWeid = 0.0, wayHours = 0.0;
			for (int i = 0; i < 3; i++) {
				if (getline(file, input)) {
					countLines++;
					if (contains(input, TOWN_NAME_STRING) ||
						contains(input, TOWN_WAY_HOURS_STRING) ||
						contains(input, TOWN_VOLUME_WEID_STRING)) {
						try {
							bool isInput = false;
							inputField(input, TOWN_NAME_STRING, name, isInputName, isInput);
							inputField(input, TOWN_WAY_HOURS_STRING, wayHours, isInputWayHours, isInput);
							inputField(input, TOWN_VOLUME_WEID_STRING, volumeWeid, isInputVolumeWeid, isInput);
							if (!isInput)
								unrecognizedStrings.add(input);
						}
						catch (int resultCode) {
							if (resultCode == -1) {
								/*std::string oldInput = input;
								int countLinesStart = countLines;
								while (true) {
									if (getline(file, input)) {
										countLines++;
										if (input.substr(input.find_last_of("=")) != oldInput.substr(oldInput.find_last_of("=")))
											break;
									}
									else
										break;			
								}
								Logger::printWarning("—о строки " + std::to_string(countLinesStart) + " до строки " + std::to_string(countLines)
									+ " данные не могут быть считаны");
								break;*/
								Logger::printWarning("ƒанные в строке " + std::to_string(countLines) + " данные не могут быть считаны");
							}
						}
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