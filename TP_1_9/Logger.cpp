#include "Logger.h"

std::string Logger::builder_string = PRINT_BUILDER_STRING;
std::string Logger::copy_builder_string = PRINT_COPY_BUILDER_STRING;
std::string Logger::deconstructor_string = PRINT_DECONSTRUCTOR_STRING;

void Logger::printMessage(std::string message) {
	SetColor(8, 0);
	printToConsole(message);
	SetColor(15, 0);
}

void Logger::printBuilder(std::string name) {
	printMessage(builder_string + name);
}

void Logger::printCopyBuilder(std::string name) {
	printMessage(copy_builder_string + name);
}

void Logger::printDeconstuctor(std::string name) {
	printMessage(deconstructor_string + name);
}

void Logger::printWarning(std::string message) {
	SetColor(4, 0);
	printToConsole(message);
	SetColor(15, 0);
}

void Logger::printToConsole(std::string s) {
	std::cout << s << std::endl;
}

void Logger::SetColor(int text, int background) {
	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleHandle, (WORD)((background << 4) | text));
}