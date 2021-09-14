#include <iostream>

const std::string PRINT_BUILDER_STRING = "������ ����������� ";
const std::string PRINT_DECONSTUCTOR_STRING = "������ ���������� ";

static void printBuilder(std::string name) {
	std::cout << PRINT_BUILDER_STRING << name << std::endl;
}

static void printDeconstuctor(std::string name) {
	std::cout << PRINT_DECONSTUCTOR_STRING << name << std::endl;
}