#include "HashTableTester.h"
#include <string>
#include <iostream>
HashTableTester::HashTableTester(const bool useConsoleOutput)
	:m_useConsoleOutput(useConsoleOutput)
{}

void HashTableTester::test(int size)
{
	m_size = size;
	std::cout << "\nStart testing\n";
	remove();
	assign();
	search();
	clear();
	destructor();
	std::cout << "\nTesting complete\n";
	getchar();
}

void HashTableTester::check_clear(HashTable table, int size)
{
	assert(table.getSize() == size);
}

void HashTableTester::chech_assign(HashTable table, int size)
{
	assert(table.getSize() == size);
}

void HashTableTester::destructor()
{
	HashTable table;
	int count = 0;
	for (int i = 0; i < m_size; i++)
		if (table.getNodes()[i])
			count++;
	assert(count == 0);
	std::cout << "Destructor testing end.\n";
}

void HashTableTester::search()
{
	HashTable table(m_size);
	for (int i = 0; i < m_size; i++)
		table.insert(i, "test");

	for (int i = 0; i < m_size; i++)
		assert(table.searchKey(i) == true);

	std::cout << "Search testing ended.\n";
}

void HashTableTester::clear()
{
	HashTable table(m_size);
	std::string value = "test";
	for (int i = 0; i < m_size; i++) {
		table.insert(i, value);
	}
	table.clearTable();
	check_clear(table, 0);
	std::cout << "Clear testing end.\n";

}

void HashTableTester::assign()
{
	HashTable table1(m_size);
	std::string value = "test";
	for (int i = 0; i < m_size; i++) {
		table1.insert(i, value);
	}
	HashTable table2(table1);
	chech_assign(table2, m_size);
	for (int i = 0; i < m_size; i++) {
		assert(table1.getNodes()[i]->key() == table2.getNodes()[i]->key());
		assert(table1.getNodes()[i]->value() == table2.getNodes()[i]->value());
	}
	std::cout << "Assign testing end.\n";

}

void HashTableTester::remove()
{
	HashTable table(m_size);
	std::string value = "test";
	for (int i = 0; i < m_size; i++) {
		table.insert(i, value);
	}
	table.remove(table.getNodes()[m_size - 1]->key());
	table.remove(table.getNodes()[m_size / 2]->key());
	table.remove(table.getNodes()[0]->key());

	assert(table.getNodes()[m_size - 1] == nullptr); // last key
	assert(table.getNodes()[m_size / 2] == nullptr); // middle key
	assert(table.getNodes()[0] == nullptr); // first key
	std::cout << "Remove testing end.\n";

}
