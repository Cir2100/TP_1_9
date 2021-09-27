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

public:
	Base() { Logger::printBuilder("Base"); };
	Base(const Base& base) { Logger::printCopyBuilder("Base"); };
	~Base() { Logger::printDeconstuctor("Base"); };

	virtual void inputFromConsole() = 0;
	virtual void inputFromFile(std::ifstream& file, std::string& tmpString, int& countLines) = 0;
	virtual void print(std::ostream& out, std::string number) = 0;
	virtual void change() = 0;
};

