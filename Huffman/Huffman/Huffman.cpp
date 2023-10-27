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
	std::string encodedText;
	std::string decodedText;
	//std::string TestEncode("010111001110100000011010111111");
	HuffmanTree tree;       

	std::string text("aaaa");

	tree.build(text);

	std::cout << "\n";

	//tree.decode(tree.root(), i = 5, TestEncode);
	//std::cout << "\ndecode: " << decodeText << '\n';

	

	std::cout << "\nText: " << text << " size:" << text.size() << '\n';
	//tree.codePrint(tree.root(), encodedText);
	double compressionRatio = 0;
	compressionRatio = tree.encode(text, encodedText);
	std::cout << "\nEncoded text " << encodedText;
	tree.decode(encodedText, decodedText);
	std::cout << "\nDecoded text " << decodedText << " size: " << decodedText.size() << '\n';
	std::cout << "\ncompressionRatio " << compressionRatio << '\n';


}