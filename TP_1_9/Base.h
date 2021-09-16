#pragma once
#include "Strings.h"
#include "MyArray.h"
#include "Logger.h"

class Base
{

public:
	Base() { Logger::printBuilder("Base"); };
	Base(const Base& base) { Logger::printCopyBuilder("Base"); };
	~Base() { Logger::printDeconstuctor("Base"); };

	virtual void print(std::ostream& out, std::string number) = 0;
	virtual void input(std::istream& in) = 0;
	//virtual Base& operator=(const Base& base) = 0;
};

