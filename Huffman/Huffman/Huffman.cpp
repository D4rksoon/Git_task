#include <Windows.h>
#include <iostream>
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
	std::string encodeText;
	std::string decodeText;
	std::string TestEncode("0000010110110111");
	HuffmanTree tree;

	std::string text("aafafedceebb");

	tree.build(text);

	//tree.codePrint(tree.root(), encodeText);

	std::cout << "\n";

	//tree.decode(tree.root(), i = 5, TestEncode);
	std::cout << "\n";
	//std::cout << "\ndecode: " << decodeText << '\n';

	int s = 0;
	s = tree.encode(tree.root(), encodeText);
	std::cout << "\nSUM " << s << '\n';
}