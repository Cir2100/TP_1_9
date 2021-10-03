#include "Coder.h"

Coder::Coder(std::string filename)
{
	file.open(filename, std::ios::binary);
	Logger::printBuilder("Coder");
}

Coder::Coder(const Coder& coder)
	: buffer(coder.buffer)
{
	Logger::printCopyBuilder("Coder");
}

Coder::~Coder() { //refact
	printTwoByte(0);
	printTwoByte(0);
	char data = '^';
	file.write((char*)&data, 1);
	file.close();
	Logger::printDeconstuctor("Coder"); 
}

void Coder::encodeBlocLZ77(MyArray<std::string> strings) {
	char data;
	for (int i = 0; i < strings.getSize(); i++)
		for (int j = 0; j < strings[i].size(); j++) {
			int offset, lenght;
			findMatching(strings[i], j, offset, lenght);
			shiftBuffer(strings[i], j, lenght + 1);
			j += lenght;
			printTwoByte(offset);
			printTwoByte(lenght);
			data = strings[i][j];
			file.write((char*)&data, 1);
		}
}
//refact
void Coder::findMatching(const std::string& s, int index, int& offset, int& lenght) {
	int pos = buffer.find(s[index]);
	if (pos == std::string::npos) {
		offset = 0;
		lenght = 0;
	}
	else {
		offset = buffer.size() - pos;
		lenght = 1;
		pos++;
		index++;
		while (buffer[pos] == s[index]) {
			lenght++;
			pos++;
			index++;
			if (index == s.size())
				break;
		}
	}
}

void Coder::shiftBuffer(const std::string& s, int index, int lenght) {
	int MAX_LEN = 65535;
	if (buffer.size() > MAX_LEN - lenght) {
		std::string tmp;
		for (int i = buffer.size() - MAX_LEN + lenght; i < buffer.size(); i++)
			tmp.push_back(buffer[i]);
		buffer = tmp;
	}

	for (int i = index; i < index + lenght; i++)
		buffer.push_back(s[i]);
}

std::string Coder::decToBin(int dec, int size)
{
	std::string ans;
	while (dec > 0)
	{
		if (dec % 2 == 0)
			ans.push_back('0');
		else
			ans.push_back('1');
		dec /= 2;
	}
	for (int i = ans.size(); i < size; i++)
		ans.push_back('0');
	reverse(ans.begin(), ans.end());
	return ans;
}

int Coder::binToDec(std::string s) {
	int dec = 0;
	int st = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		dec += (s[i] - '0') * st;
		st *= 2;
	}
	return dec;
}

void Coder::printTwoByte(int dec) {
	char bytes[2];
	std::string bin = decToBin(dec, 16);
	bytes[0] = binToDec(bin.substr(0, 8));
	bytes[1] = binToDec(bin.substr(8, 8));
	file.write(bytes, 2);
}
