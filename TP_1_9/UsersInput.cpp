#include "UsersInput.h"

int processingInputI(int minInput, int maxInput)
{
	while (true)
	{
		int type;
		std::cin >> type;
		if (std::cin.fail() || type < minInput || type > maxInput)
		{
			std::cin.clear();
			std::cout << "������� �������� �����.\n������� ��������: ";
		}
		else
		{
			return type;
		}
		std::cin.ignore(32767, '\n');
	}
}

double processingInputD(double minInput, double maxInput)
{
	while (true)
	{
		double type;
		std::cin >> type;
		if (std::cin.fail() || type < minInput || type > maxInput)
		{
			std::cin.clear();
			std::cout << "������� �������� �����.\n������� ��������: ";
		}
		else
		{
			return type;
		}
		std::cin.ignore(32767, '\n');
	}
}

//��������� ����� �������� ����a
//���� 0 �������� ����� �� ����� ������ �� �����.
void ProcessInputNameOfInputFile(std::ifstream& input)
{
	//��������� �������� �����
	std::string filename;
	bool isCorrect;
	std::cout << "������� �������� ����� (� �����������): ";
	std::cin >> filename;
	isCorrect = checkFilename(filename);
	if (isCorrect)
		input.open(filename);
	while (!input.is_open() && filename[0] != '0')
	{
		if (isCorrect)
			std::cout << "������ ����� �� ����������." << std::endl;
		std::cout << "������� �������� �������� (� �����������): ";
		std::cin >> filename;
		isCorrect = checkFilename(filename);
		if (isCorrect)
			input.open(filename);
	}
	if (filename[0] != '0')
		std::cout << "���� ������� ������" << std::endl;
	else
		std::cout << "�� ���������� �� ����� ������ �� �����" << std::endl;
}
//�������� ������������ ����� �����
bool checkFilename(std::string file)
{
	if ((((file[0] == 'c') || (file[0] == 'C')) && ((file[1] == 'o') || (file[1] == 'O'))
		&& ((file[2] == 'n') || (file[2] == 'N')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'a') || (file[0] == 'A')) && ((file[1] == 'u') || (file[1] == 'U'))
			&& ((file[2] == 'x') || (file[2] == 'X')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'p') || (file[0] == 'P')) && ((file[1] == 'r') || (file[1] == 'R'))
			&& ((file[2] == 'n') || (file[2] == 'N')) && ((file[3] == '.') || (file[3] == '\0')))
		|| (((file[0] == 'c') || (file[0] == 'C')) && ((file[1] == 'o') || (file[1] == 'O'))
			&& ((file[2] == 'm') || (file[2] == 'M')) && ((file[3] == '1') || (file[3] == '2')
				|| (file[3] == '3') || (file[3] == '4') || (file[3] == '5') || (file[3] == '6')
				|| (file[3] == '7') || (file[3] == '8') || (file[3] == '9')) && ((file[4] == '.')
					|| (file[4] == '\0'))) || (((file[0] == 'l') || (file[0] == 'L')) && ((file[1] == 'p')
						|| (file[1] == 'P')) && ((file[2] == 't') || (file[2] == 'T')) && ((file[3] == '1')
							|| (file[3] == '2') || (file[3] == '3') || (file[3] == '4') || (file[3] == '5')
							|| (file[3] == '6') || (file[3] == '7') || (file[3] == '8') || (file[3] == '9'))
						&& ((file[4] == '.') || (file[4] == '\0'))))
	{
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "������ ��� ����� ������������ Windows." << std::endl;
		return false;
	}
	int i = file.size();
	if ((file[i] == '\0') && (file[i - 1] == 't') && (file[i - 2] == 'x') && (file[i - 3] == 't') && (file[i - 4] == '.'))
		return true;
	else
	{
		if (file[i - 1] != '0')
			std::cout << "���� ������ ����� ������ .txt" << std::endl;
		return false;
	}
}