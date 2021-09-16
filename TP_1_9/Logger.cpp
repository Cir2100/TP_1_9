#include "Logger.h"


std::string Logger::builder_string = PRINT_BUILDER_STRING;
std::string Logger::copy_builder_string = PRINT_COPY_BUILDER_STRING;
std::string Logger::deconstructor_string = PRINT_DECONSTRUCTOR_STRING;

void Logger::printBuilder(std::string name) {
	SetColor(8, 0);
	printToConsole(builder_string + name);
	SetColor(15, 0);
}

void Logger::printCopyBuilder(std::string name) {
	SetColor(8, 0);
	printToConsole(copy_builder_string + name);
	SetColor(15, 0);
}

void Logger::printDeconstuctor(std::string name) {
	SetColor(8, 0);
	printToConsole(deconstructor_string + name);
	SetColor(15, 0);
}

void Logger::printToConsole(std::string s) {
	SetColor(8, 0);
	std::cout << s << std::endl;
	SetColor(15, 0);
}

void Logger::SetColor(int text, int background) {
	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleHandle, (WORD)((background << 4) | text));
}