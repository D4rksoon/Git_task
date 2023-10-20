#pragma once
#include "HashTable.h"
#include <Assert.h>
class HashTableTester
{
public:
	HashTableTester(const bool useConsoleOutput);
	~HashTableTester() = default;
	void test(int size);

protected:
	void check_clear(HashTable table, int size);
	void chech_assign(HashTable table, int size);
private:
	void clear();
	void assign();
	void remove();
	void destructor();
	void search();

private:
	int m_size;
	bool m_useConsoleOutput;
};

