#include "CarsTown.h"

CarsTown::CarsTown(std::string _name, double _volumeWeid, double _wayHours) 
	: name(_name), volumeWeid(_volumeWeid), wayHours(_wayHours)
	{ /*Logger::printBuilder("CarsTown");*/ }

CarsTown::CarsTown(const CarsTown& carsTown)
	: name(carsTown.name), volumeWeid(carsTown.volumeWeid), wayHours(carsTown.wayHours)
	{ /*Logger::printCopyBuilder("CarsTown");*/ }

void CarsTown::inputFromConsole(int number) {
	inputData("Введите название города " + std::to_string(number) + ": ", name);
	inputData("Введите объем груза для города " + std::to_string(number) + ": ", volumeWeid, 0.0, double(INT32_MAX));
	inputData("Введите время в пути для города " + std::to_string(number) + ": ", wayHours, 0.0, double(INT32_MAX));
}

void CarsTown::inputFromFile(std::string& input, std::ifstream& file, int& countLines, MyArray<std::string>& unrecognizedStrings, 
	bool& stopInput, bool& isInputName, bool& isInputWayHours, bool& isInputVolumeWeid) {
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
					if (resultCode == -1)
						Logger::printWarning("Данные в строке " + std::to_string(countLines) + " не могут быть считаны");
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
}

void CarsTown::print(std::ostream& out, std::string number, std::string splitter) {
	out << TOWN_NAME_STRING << " =" << splitter << number   << std::endl;
	out << "  " << TOWN_WAY_HOURS_STRING << " =" << splitter << wayHours << std::endl;
	out << "  " << TOWN_VOLUME_WEID_STRING << " =" << splitter << volumeWeid << std::endl;
}