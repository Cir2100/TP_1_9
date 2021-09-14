#include <iostream>

const std::string PRINT_BUILDER_STRING = "Вызван конструктор ";
const std::string PRINT_DECONSTUCTOR_STRING = "Вызван деструктор ";

static void printBuilder(std::string name) {
	std::cout << PRINT_BUILDER_STRING << name << std::endl;
}

static void printDeconstuctor(std::string name) {
	std::cout << PRINT_DECONSTUCTOR_STRING << name << std::endl;
}