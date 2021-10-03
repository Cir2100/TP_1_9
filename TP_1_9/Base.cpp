#include "Base.h"

Base::Base(std::string _name) : name(_name) 
	{ Logger::printBuilder("Base"); };

Base::Base(const Base& base) : name(base.name), unrecognizedStrings(base.unrecognizedStrings)
	{ Logger::printCopyBuilder("Base"); };

void Base::print(std::ostream& out, std::string number, std::string type) {
	out << name << number << ":" << std::endl;
}

void Base::printUnrecognizedStrings(std::ostream& out) {
	if (unrecognizedStrings.getSize() > 0) {
		out << UNRECOGNIZED_STRINGS_STRING << std::endl;
		for (int i = 0; i < unrecognizedStrings.getSize(); i++)
			out << unrecognizedStrings[i] << std::endl;
	}
}

MyArray<std::string> Base::toStringArray(std::string number) {
	MyArray<std::string> strings;
	strings.add(name + number + ":\n");
	return strings;
}