#pragma once
#include "Strings.h"
#include <iostream>

class Base
{

public:
	Base() { printBuilder("Base"); };
	Base(const Base& base) { printBuilder("Base"); };
	~Base() { printDeconstuctor("Base"); };

	virtual void print(std::ostream& out) = 0;
	virtual void input(std::istream& in) = 0;
};

