#pragma once
#include "Logger.h"
#include "MyArray.h" // del?
#include <fstream>
#include <iostream>

class Coder
{
private:
	std::string buffer;
	std::ofstream file;

	void findMatching(const std::string& s, int index, int& offset, int& lenght);
	void shiftBuffer(const std::string& s, int index, int lenght);
	std::string decToBin(int dec, int size = 0);
	int binToDec(std::string s);
	void printTwoByte(int dec);
public:
	Coder(std::string filename = "codefile.dat");
	Coder(const Coder& coder);
	~Coder();

	//void encodeLZ77();
	void encodeBlocLZ77(MyArray<std::string> strings);
};

