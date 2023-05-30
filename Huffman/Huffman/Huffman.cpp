#include <iostream>
#include <fstream>
#include <Windows.h>
#include "HuffmanTree.h"

void Table(const std::string& text, int Tab[256])
{
	int n = text.length();
	for (int i = 0; i < n; i++) {
		Tab[text[i]]++;
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int i = 0;
	std::string fileName("textFile.txt");
	std::string text("abcd");
	std::ofstream file(fileName);
	file << text;
	int Tab[256] = {0};
	Table(text, Tab);
	for (int i = 0; i < 256; i++) {
		std::cout << Tab[i];
	}
	int symb = Tab[text[0]];
	std::cout << "\nText " << text[0] << ' ';
	std::cout << "= " << symb << '\n';
}
