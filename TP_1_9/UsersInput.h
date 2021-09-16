#pragma once
#include <iostream>
#include <fstream>

int processingInputI(int minInput, int maxInput);
double processingInputD(double minInput, double maxInput);
void ProcessInputNameOfInputFile(std::ifstream& input);
bool checkFilename(std::string file);