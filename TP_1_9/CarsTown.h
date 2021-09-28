#pragma once
#include "Strings.h"
#include "FileInput.h"
#include "UsersInput.h"
#include <iostream>
#include <string>

class CarsTown
{
public:
	std::string name;
	double volumeWeid, wayHours;

	CarsTown(std::string _name = MY_NULL_STRING, double _volumeWeid = 0.0, double _wayHours = 0.0);
	CarsTown(const CarsTown& carsTown);
	~CarsTown() { /*Logger::printDeconstuctor("CarsTown");*/ };

	virtual void inputFromConsole(int number);
	virtual void inputFromFile(std::string& input, std::ifstream& file, int& countLines, MyArray<std::string>& unrecognizedStrings,
		bool& stopInput, bool& isInputName, bool& isInputWayHours, bool& isInputVolumeWeid);
	virtual void print(std::ostream& out, std::string number = "", std::string splitter = " ");
};

