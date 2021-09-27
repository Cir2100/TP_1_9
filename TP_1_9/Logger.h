#pragma once
#include "Strings.h"
#include <iostream>
#include<windows.h>

class Logger
{
private:

	static std::string builder_string;
	static std::string copy_builder_string;
	static std::string deconstructor_string;

    static void SetColor(int text, int background);
    static void printToConsole(std::string s);
public:

	static void printMessage(std::string message);
	static void printWarning(std::string message);
	static void printBuilder(std::string name);
	static void printCopyBuilder(std::string name);
	static void printDeconstuctor(std::string name);
	

};
