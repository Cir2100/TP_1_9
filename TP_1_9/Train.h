#pragma once
#include "Base.h"
class Train :
    public Base
{
private:
	int yearRelease, countWagons;
	double volumeWeid;
	std::string name;
	MyArray<std::string> route;
public:
	Train(std::string _name = MY_NULL_STRING, double _volumeWeid = 0.0, int _yearRelease = 0, int _countWagons = 0,
		MyArray<std::string> route = MyArray<std::string>());
	Train(const Train& train);
	~Train() { Logger::printDeconstuctor("Train"); }

	virtual void print(std::ostream& out);
	virtual void input(std::istream& in);
	Train& operator=(const Train& train);

	int getYearRelease() { return yearRelease; }
	void setYearRelease(int _yearRelease) { yearRelease = _yearRelease; }

	int getCountWagons() { return countWagons; }
	void setCountWagons(int _countWagons) { countWagons = countWagons; }

	std::string getName() { return name; }
	void setName(std::string _name) { name = _name; }

	double getVolumeWeid() { return volumeWeid; }
	void setVolumeWeid(double _volumeWeid) { volumeWeid = _volumeWeid; }

	MyArray<std::string> getRoute() { return route; }
	void setRoute(MyArray<std::string> _route) { route = _route; }
};

