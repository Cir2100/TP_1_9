#include "UsersInput.h"


int chouseStream() {
	std::cout << "1. ����" << std::endl;
	std::cout << "2. �������" << std::endl;
	std::cout << "0. ������" << std::endl;
	return processingInput(0, 2);
}

int chouseObject() {
	std::cout << "1. �������" << std::endl;
	std::cout << "2. ����������" << std::endl;
	std::cout << "3. �����" << std::endl;
	std::cout << "0. ������" << std::endl;
	return processingInput(0, 3);
}

//��������� ����� �������� ����a
//���� 0 �������� ����� �� ����� ������ �� �����.
bool processInputNameOfInputFile(std::ifstream& file)
{
	//��������� �������� �����
	std::string filename;
	bool isCorrect;
	std::cout << "������� �������� ����� (� �����������): ";
	std::cin >> filename;
	isCorrect = checkFilename(filename);
	if (isCorrect)
		file.open(filename);
	while (!file.is_open() && filename[0] != '0')
	{
		if (isCorrect)
			std::cout << "������ ����� �� ����������." << std::endl;
		std::cout << "������� �������� �������� (� �����������): ";
		std::cin >> filename;
		isCorrect = checkFilename(filename);
		if (isCorrect)
			file.open(filename);
	}
	if (filename[0] != '0') {
		std::cout << "���� ������� ������" << std::endl;
		return true;
	}
	else {
		std::cout << "�� ���������� �� ����� ������ �� �����" << std::endl;
		return false;
	}
		
}
//��������� ����� ��������� ����a
//���� 0 �������� ����� �� ����� ������ �� �����.
std::string processInputNameOfOutputFile()
{
	//��������� �������� �����
	std::string filename;
	bool isCorrect;
	std::cout << "������� �������� ����� (� �����������): ";
	std::cin >> filename;
	isCorrect = checkFilename(filename);
	while (!isCorrect) {
		std::cin >> filename;
		isCorrect = checkFilename(filename);
	}
	return filename;
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

void inputData(std::string help, std::string& data) {
	std::cout << help;
	getline(std::cin, data);
}