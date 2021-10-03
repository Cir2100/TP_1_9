#include "Decoder.h"

Decoder::Decoder(std::string filename)
{
	codefile.open(filename, std::ios::binary);
	Logger::printBuilder("Decoder");
}

Decoder::Decoder(const Decoder& decoder)
	: buffer(decoder.buffer)
{
	Logger::printCopyBuilder("Decoder");
}

Decoder::~Decoder() {
	Logger::printDeconstuctor("Decoder");
}

void Decoder::decodeLZ77() {
	outfile.open("tmp.txt");
	char data[1];
	int offset = 0, lenght;
	while (true) {
		lenght = inputTwoByte();
		if (lenght > 0)
			offset = inputTwoByte();
		codefile.read(data, 1);
		if (offset > buffer.size())
			break;
		shiftBuffer(lenght, offset, data[0]);
	}

	int unreadSimbols = 0;
	while (!codefile.eof()) {
		codefile.read(data, 1);
		unreadSimbols++;
	}
	if (unreadSimbols > 0)
		Logger::printWarning("Файл не может декодирован");

	outfile << buffer;
	outfile.close();
	codefile.close();
}

void Decoder::shiftBuffer(int lenght, int offset, char simbol) {
	int MAX_LEN = 1000;
	if (lenght > 0) {
		int start = buffer.size() - offset;
		for (int i = 0; i < lenght; i++)
			buffer += buffer[start + i];
	}
	buffer += simbol;
	if (buffer.size() > MAX_LEN) {
		std::string tmp;
		//print pop elements
		for (int i = 0; i < (int)buffer.size() - MAX_LEN; i++)
			outfile << buffer[i];

		for (int i = (int)buffer.size() - MAX_LEN; i < buffer.size(); i++)
			tmp.push_back(buffer[i]);
		buffer = tmp;
	}
}

int Decoder::binToDec(std::string s) {
	int dec = 0;
	int st = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		dec += (s[i] - '0') * st;
		st *= 2;
	}
	return dec;
}

std::string Decoder::decToBin(int dec, int size)
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

int Decoder::inputTwoByte() {
	char data[2];
	unsigned char byte1, byte2;
	codefile.read(data, 2);
	byte1 = data[0];
	byte2 = data[1];
	return binToDec(decToBin(byte1, 8) + decToBin(byte2, 8));
}