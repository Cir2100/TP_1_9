#pragma once
#include "Base.h"

class Plane :
    public Base
{
private:
	std::string type, name;
	MyArray<std::string> towns;
	double volumeWeid, width, lengt, height;

	void inputTownsFromConsole();
	void inputTownsFromFile(std::string& input, const std::string& nameField,
		bool& isInputField, std::ifstream& file, int& countLines, bool& isInput);
public:

	Plane(std::string _type = MY_NULL_STRING, std::string _name = MY_NULL_STRING, double _volumeWeid = 0.0, double _width = 0.0,
		double _lengt = 0.0, double _height = 0.0, MyArray<std::string> _towns = MyArray<std::string>());
	Plane(const Plane& plane);
	~Plane() { Logger::printDeconstuctor("Plane"); }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpString, int& countLines);
	virtual void print(std::ostream& out, std::string number = "", std::string splitter = " ");
	virtual void change();
	virtual MyArray<std::string> toStringArray(std::string number);
	Plane& operator=(const Plane& plane);


	std::string getType() { return type; }
	void setType(std::string _type) { type = _type; }

	std::string getName() { return name; }
	void setName(std::string _name) { name = _name; }

	double getVolumeWeid() { return volumeWeid; }
	void setVolumeWeid(double _volumeWeid) { volumeWeid = _volumeWeid; }

	double getWidth() { return width; }
	void setWidth(double _width) { width = _width; }

	double getLengt() { return lengt; }
	void setLengt(double _lengt) { lengt = _lengt; }

	double getHeight() { return height; }
	void setHeight(double _height) { height = _height; }

	MyArray<std::string> getTowns() { return towns; }
	void setTowns(MyArray<std::string> _towns) { towns = _towns; }
};

