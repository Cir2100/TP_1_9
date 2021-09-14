#pragma once
#include "Base.h"
class Plane :
    public Base
{
private:

public:
	Plane() { printBuilder("Plane"); };
	Plane(const Plane& plane) { printBuilder("Plane"); };
	~Plane() { printDeconstuctor("Plane"); };

	virtual void print(std::ostream& out);
	virtual void input(std::istream& in);
};

