#pragma once
#include "Base.h"
#include "CarsTown.h"

class Car :
    public Base
{

private:
	int yearRelease;
	std::string mark, model;
	MyArray<CarsTown> towns;

	void inputTownsFromConsole();
	void inputTownsFromFile(std::string& input, const std::string& nameField,
		bool& isInputField, std::ifstream& file, int& countLines, bool& isInput);
public:
	Car(std::string _mark = MY_NULL_STRING, std::string _model = MY_NULL_STRING, 
		int _yearRelease = 0.0, MyArray<CarsTown> _towns = MyArray<CarsTown>());
	Car(const Car& car);
	~Car() { Logger::printDeconstuctor("Car"); };

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpString, int& countLines);
	virtual void print(std::ostream& out, std::string number = "", std::string splitter = " ");
	virtual void change();
	virtual MyArray<std::string> toStringArray(std::string number);
	Car& operator=(const Car& car);

	std::string getMark() { return mark; }
	void setMark(std::string _mark) { mark = _mark; }

	std::string getModel() { return model; }
	void setModel(std::string _model) { model = _model; }

	int getYearRelease() { return yearRelease; }
	void setYearRelease(int _yearRelease) { yearRelease = _yearRelease; }

	MyArray<CarsTown> getTowns() { return towns; }
	void setTowns(MyArray<CarsTown> _towns) { towns = _towns; }
};

