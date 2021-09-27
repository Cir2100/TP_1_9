#pragma once
#include "MyArray.h"
#include "Strings.h"
#include "Logger.h"
#include <fstream>
#include <string>

template <typename T>
void inputField(std::string& input, const std::string& nameField, T& field, bool& isInputField, bool& isInput);
void checkInput(const std::string& input, std::string& field);
void checkInput(const std::string& input, int& field);
void checkInput(const std::string& input, double& field);
bool contains(const std::string& str, const std::string& substr);

template <typename T>
void inputField(std::string& input, const std::string& nameField, T& field, bool& isInputField, bool& isInput) {
	if (contains(input, nameField)) {
		if (!isInputField) {
			input = input.substr(input.find_last_of("=") + 2);
			checkInput(input, field);
			isInputField = true;
			isInput = true;
		}
		else
			throw - 1;
	}
}