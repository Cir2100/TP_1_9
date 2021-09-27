#pragma once
#include "Strings.h"
#include "MyArray.h"
#include "Logger.h"
#include "FileInput.h"
#include "UsersInput.h"
#include <fstream>
#include <string>

class Base
{
private:
	std::string name;
protected:
	MyArray<std::string> unrecognizedStrings;

public:
	Base(std::string _name = MY_NULL_STRING) : name(_name) { Logger::printBuilder("Base"); };
	Base(const Base& base);
	~Base() { Logger::printDeconstuctor("Base"); };

	virtual void inputFromConsole() = 0;
	virtual void inputFromFile(std::ifstream& file, std::string& tmpString, int& countLines) = 0;
	virtual void print(std::ostream& out, std::string number);
	virtual void printUnrecognizedStrings(std::ostream& out);
	virtual void change() = 0;
};

