#pragma once
#include "MyArray.h"
#include "Plane.h"
#include "Car.h"
#include "Train.h"
#include <fstream>
#include <string>

Plane inputPlaneFromFile(std::ifstream& file, std::string& tmpString, int& countLines);
Car inputCarFromFile(std::ifstream& file, std::string& tmpString, int& countLines);
Train inputTrainFromFile(std::ifstream& file, std::string& tmpString, int& countLines);
void checkInput(const std::string& input, std::string& field);
void checkInput(const std::string& input, int& field);
void checkInput(const std::string& input, double& field);
bool contains(const std::string& str, const std::string& substr);
template <typename T>
void inputField(std::string& input, const std::string& nameField, T& field, bool& isInputField);
void inputTowns(std::string& input, const std::string& nameField, MyArray<std::string>& towns, 
	bool& isInputField, std::ifstream& file, int& countLines);
void inputTowns(std::string& input, const std::string& nameField, MyArray<CarsTown>& towns, 
	bool& isInputField, std::ifstream& file, int& countLines);