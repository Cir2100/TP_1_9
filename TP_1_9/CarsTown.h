#pragma once
#include <iostream>

struct CarsTown
{
	std::string name;
	double volumeWeid, wayHours;

	CarsTown(std::string _name = MY_NULL_STRING, double _volumeWeid = 0.0, double _wayHours = 0.0)
	{
		name = _name;
		volumeWeid = _volumeWeid;
		wayHours = _wayHours;
	}
};