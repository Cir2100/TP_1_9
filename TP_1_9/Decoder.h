#pragma once
#include "Logger.h"
#include <fstream>
#include <iostream>

class Decoder
{
private:
	std::string buffer;
	std::ifstream codefile;
	std::ofstream outfile;

	void shiftBuffer(int lenght, int offset, char simbol);
	int binToDec(std::string s);
	std::string decToBin(int dec, int size = 0);
	int inputTwoByte();
public:
	Decoder(std::string filename = "codefile.dat");
	Decoder(const Decoder& decoder);
	~Decoder();

	void decodeLZ77();
};

