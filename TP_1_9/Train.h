#pragma once
#include "Base.h"
class Train :
    public Base
{
public:
	Train() { printBuilder("Train"); };
	Train(const Train& train) { printBuilder("Train"); };
	~Train() { printDeconstuctor("Train"); };

	virtual void print(std::ostream& out);
	virtual void input(std::istream& in);
};

