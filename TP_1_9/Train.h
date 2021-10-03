#pragma once
#include "Base.h"
class Train :
    public Base
{
private:
	int yearRelease, countWagons;
	double volumeWeid;
	std::string name;
	MyArray<std::string> towns;

	void inputTownsFromConsole();
	void inputTownsFromFile(std::string& input, const std::string& nameField,
		bool& isInputField, std::ifstream& file, int& countLines, bool& isInput);
public:
	Train(std::string _name = MY_NULL_STRING, double _volumeWeid = 0.0, int _yearRelease = 0, int _countWagons = 0,
		MyArray<std::string> _towns = MyArray<std::string>());
	Train(const Train& train);
	~Train() { Logger::printDeconstuctor("Train"); }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpString, int& countLines);
	virtual void print(std::ostream& out, std::string number = "", std::string splitter = " ");
	virtual void change();
	virtual MyArray<std::string> toStringArray(std::string number);
	Train& operator=(const Train& train);

	int getYearRelease() { return yearRelease; }
	void setYearRelease(int _yearRelease) { yearRelease = _yearRelease; }

	int getCountWagons() { return countWagons; }
	void setCountWagons(int _countWagons) { countWagons = countWagons; }

	std::string getName() { return name; }
	void setName(std::string _name) { name = _name; }

	double getVolumeWeid() { return volumeWeid; }
	void setVolumeWeid(double _volumeWeid) { volumeWeid = _volumeWeid; }

	MyArray<std::string> getRoute() { return towns; }
	void setRoute(MyArray<std::string> _route) { towns = _route; }
};

