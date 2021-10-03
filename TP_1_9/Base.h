#pragma once
#include "Strings.h"
#include "MyArray.h"
#include "Logger.h"
#include "FileInput.h"
#include "UsersInput.h"

#include "Decoder.h"
#include "Coder.h"

#include <fstream>
#include <string>

class Base
{
private:
	std::string name;
protected:
	MyArray<std::string> unrecognizedStrings;

public:
	Base(std::string _name = MY_NULL_STRING);
	Base(const Base& base);
	~Base() { Logger::printDeconstuctor("Base"); };

	virtual void inputFromConsole() = 0;
	virtual void inputFromFile(std::ifstream& file, std::string& tmpString, int& countLines) = 0;
	virtual void print(std::ostream& out, std::string number, std::string splitter = " ");
	virtual void printUnrecognizedStrings(std::ostream& out);
	virtual void change() = 0;
	virtual MyArray<std::string> toStringArray(std::string number);

};

