#include "FileInput.h"

void checkInput(const std::string& input, std::string& field) {
	field = input;
}

void checkInput(const std::string& input, int& field) {
	bool sign = false, err = false;
	int result = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
			result = result * 10 + (input[i] - '0');
		else if (i == 0 && input[i] == '-')
			sign = true;
		else
			err = true;
	}

	if (sign)
		result = -result;

	if (!err)
		field = result;
	else
		field = 0;
}

void checkInput(const std::string& input, double& field) {
	bool sign = false, flpoint = false, err = false;
	double result = 0, d = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			if (flpoint) {
				result += (input[i] - '0') * d;
				d /= 10;
			}
			else
				result = result * 10 + (input[i] - '0');
		}
		else if (i == 0 && input[i] == '-')
			sign = true;
		else if (i != 0 && input[i] == '.') {
			flpoint = true;
			d = 0.1;
		}
		else
			err = true;
	}

	if (sign)
		result = -result;

	if (!err)
		field = result;
	else
		field = 0.0;
}

bool contains(const std::string& str, const std::string& substr) {
	return (str.find(substr) != std::string::npos);
}