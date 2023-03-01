#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <ios>


bool createFileWithRandNum(const std::string& fileName, const int numCount, const int maxNum)
{
	std::ofstream file(fileName);
	if (!file.is_open())
		return false;
	for (int i = 0; i < numCount; i++)
	{
		int x = rand() % maxNum;
		file << x << ' ';
	}
}
bool checkOnSorted(const std::string& fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open()) {
		throw("Error open file");
		return false;
	}
	int value;
	int tmp;
	file >> tmp;
	while (file >> value) {
		if (tmp > value) {
			return false;
		}
		tmp = value;
	}
}

int main()
{

}