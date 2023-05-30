#include "HashTable.h"
#include<vector>

HashTable::HashTable(int size)
{
	m_size = size;
	Nodes.resize(size);
}

void HashTable::setSize(const int size)
{
	m_size = size;
}

int HashTable::getSize() const
{
	return m_size;
}


int HashTable::hashCode(int key)
{
	const double a = -(1 - sqrt(5) / 2); // ��������� 
	int size = getSize(); // ����� ������� ��������
	int N = size + (size % 10); // ������ �������
	return fmod(fmod(key, N) * a * N, N);
}
