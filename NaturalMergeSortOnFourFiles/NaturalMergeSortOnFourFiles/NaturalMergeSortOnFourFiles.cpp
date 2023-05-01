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
		int x = (rand() * rand()) % maxNum; // Позволяет генерировать число больше 32757
		file << x << ' ';
	}
	return true;
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
	return true;
}
bool fileIsEmpty(std::fstream* fileA, std::fstream* fileB)
{
	const int n = 2;
	for (int i = 0; i < n; i++) {
		std::string fileNameA = "fileA" + std::to_string(i) + ".txt";
		std::string fileNameB = "fileB" + std::to_string(i) + ".txt";
		fileA[i].open(fileNameA, std::ios::in);
		fileB[i].open(fileNameB, std::ios::in);
		if (!fileB[i].is_open() || !fileA[i].is_open())
			throw("Ошибка открытия");
		else if (fileB[i].peek() == EOF || fileA[i].peek() == EOF) {
			for (int i = 0; i < n; i++) {
				fileA[i].close();
				fileB[i].close();
			}
			return true;
		}
	}
	for (int i = 0; i < n; i++) {
		fileA[i].close();
		fileB[i].close();
	}
	return false;
}
int split(const std::string& fileName)
{
	int x, y;
	int flag = 0;
	const int n = 2;
	std::ifstream file(fileName);
	if (!file.is_open()) {
		throw("Ошибка открытия");
	}
	std::ofstream* fileA = new std::ofstream[n];
	for (int i = 0; i < n; i++) {
		std::string fileNameA = "fileA" + std::to_string(i) + ".txt";
		fileA[i].open(fileNameA);
	}
	for (int i = 0; i < n; i++) {
		if (!fileA[i].is_open())
			throw("Ошибка открытия");
	}

	file >> x; 
	while (!file.eof()) {
		fileA[flag] << x << ' ';
		while (file >> y and x <= y) { 
			x = y;
			fileA[flag] << x << ' ';   		
		}
		x = y;
		flag = 1 - flag;
	}
	file.close();
	for (int i = 0; i < n; i++) {
		fileA[i].close();
	}
	//std::cout << "split is done\n";
}
void merge(std::fstream* fileA, std::fstream* fileB)
{

	int h;
	int flag = 0;
	const int n = 2;
	int x[n];
	int y[n];
	fileA[0] >> x[0];
	fileA[1] >> x[1];
	while (!fileA[0].eof() and !fileA[1].eof()) {
		//std::cout << "merging..\n";
		if (x[0] < x[1]) {
			h = 0;
		}
		else {
			h = 1;
		}
		fileB[flag] << x[h] << ' ';
		if (fileA[h] >> y[h] and x[h] <= y[h]) {
			x[h] = y[h];
		}
		else {
			fileB[flag] << x[1 - h] << ' ';
			while (fileA[1 - h] >> y[1 - h] and x[1 - h] <= y[1 - h]) {
				x[1 - h] = y[1 - h];
				fileB[flag] << y[1 - h] << ' ';			
			}
			x[1 - h] = y[1 - h];	
			x[h] = y[h];			
			flag = 1 - flag;
		}
	}
	if (!fileA[0].eof()) {
		while (!fileA[0].eof()) {
			fileB[flag] << x[0] << ' ';
			fileA[0] >> x[0];
		}
	}
	if (!fileA[1].eof()) {
		while (!fileA[1].eof()) {
			fileB[flag] << x[1] << ' ';
			fileA[1] >> x[1];
		}
	}
	for (int i = 0; i < n; i++) {
		fileA[i].close();
		fileB[i].close();
	}
	//std::cout << "merge is done\n";
}
void writingSortedFile(const std::string& fileName, std::fstream* fileA, std::fstream* fileB) {
	const int n = 2;
	int value;
	std::ofstream file(fileName);
	if (!file.is_open()) {
		throw("Ошибка открытия\n");
	}
	for (int i = 0; i < n; i++) {
		std::string fileNameA = "fileA" + std::to_string(i) + ".txt";
		std::string fileNameB = "fileB" + std::to_string(i) + ".txt";
		fileA[i].open(fileNameA, std::ios::in);
		fileB[i].open(fileNameB, std::ios::in);
	}
	for (int i = 0; i < n; i++) {
		if (!fileB[i].is_open() || !fileA[i].is_open())
			throw("Ошибка открытия");
	}
	if (fileA[1].peek() == EOF) { // peek - берет последний элемент
		while (fileA[0] >> value) {
			file << value << ' ';
		}
	}
	if (fileB[1].peek() == EOF) {
		while (fileB[0] >> value) {
			file << value << ' ';
		}
	}
}
void sortFile(const std::string& fileName)
{
	bool check = false;
	const int n = 2;
	int value;
	std::ifstream file(fileName);
	if (!file.is_open()) {
		throw("Ошибка открытия\n");
	}
	std::fstream* fileA = new std::fstream[n];
	std::fstream* fileB = new std::fstream[n];

	split(fileName);

	while (!check) {
		for (int i = 0; i < n; i++) {
			std::string fileNameA = "fileA" + std::to_string(i) + ".txt";
			std::string fileNameB = "fileB" + std::to_string(i) + ".txt";
			fileA[i].open(fileNameA, std::ios::in);
			fileB[i].open(fileNameB, std::ios::out);
		}
		for (int i = 0; i < n; i++) {
			if (!fileB[i].is_open() || !fileA[i].is_open())
				throw("Ошибка открытия");
		}
		merge(fileA, fileB);

		if (fileIsEmpty(fileA, fileB)) {
			break;
		}

		for (int i = 0; i < n; i++) {
			std::string fileNameA = "fileA" + std::to_string(i) + ".txt";
			std::string fileNameB = "fileB" + std::to_string(i) + ".txt";
			fileB[i].open(fileNameB, std::ios::in);
			fileA[i].open(fileNameA, std::ios::out);			
		}
		for (int i = 0; i < n; i++) {
			if (!fileB[i].is_open() || !fileA[i].is_open())
				throw("Ошибка открытия");
		}
		merge(fileB, fileA);
		check = fileIsEmpty(fileA, fileB);
	}
	writingSortedFile(fileName, fileA, fileB);
}
int createAndSortFile(const std::string& fileName, int numCount, int maxNum) {
	if (!createFileWithRandNum(fileName, numCount, maxNum)) {
		return -1;
	}

	sortFile(fileName);

	if (!checkOnSorted(fileName)) {
		return -2;
	}

	return 1;
}
int main()
{
	int numCount = 10000;
	int maxNum = 100000;
	std::string fileName = "file.txt";
	for (int i = 0; i < 10; i++) {
		switch (createAndSortFile(fileName, numCount, maxNum)) {
		case 1:
			std::cout << "Test passed." << std::endl;
			break;

		case -1:
			std::cout << "Test failed: can't create file." << std::endl;
			break;

		case -2:
			std::cout << "Test failed: file isn't sorted." << std::endl;
			break;
		}

		return 0;
	}
}