#pragma once
#include "Base.h"
#include "Strings.h"
#include <iostream>

class Transporter
{
private:

public:
	Transporter() { printBuilder("Transporter"); };
	Transporter(const Transporter& transporter) { printBuilder("Transporter"); };
	~Transporter() { printDeconstuctor("Transporter"); };

	virtual void print(std::ostream& out);
	virtual void input(std::istream& in);
};

