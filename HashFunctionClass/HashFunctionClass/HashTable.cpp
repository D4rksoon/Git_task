#include "HashTable.h"
#include<vector>
#include<iostream>

HashTable::HashTable(int size)
{
	m_size = size;
	Nodes.resize(size);
}

HashTable::HashTable(const HashTable& other)
{
	m_size = other.m_size;
	this->getNodes().resize(m_size);
	for (int i = 0; i < m_size; i++) {
		/*Node* tmp = Nodes.at(i);
		while (tmp != nullptr) {
			this->insert(other.Nodes[i]->m_key);
			tmp = tmp->next;
		}*/
		Nodes[i] = other.Nodes[i];
	}
}

HashTable& HashTable::operator=(const HashTable& other)
{
	this->clear();
	m_size = other.m_size;
	this->getNodes().resize(m_size);
	for (int i = 0; i < m_size; i++) {
		/*Node* tmp = Nodes.at(i);
		while (tmp != nullptr) {
			this->insert(other.Nodes[i]->m_key);
			tmp = tmp->next;
		}*/
		Nodes[i] = other.Nodes[i];
	}
	return *this;
}

std::vector<HashTable::Node*> HashTable::getNodes()
{
	return Nodes;
}

int HashTable::operator[](int key)
{
	for (int i = 0; i < getSize(); i++) {
		Node* tmp = Nodes.at(hashCode(key));
		while (tmp != nullptr) {
			if (tmp->m_key = key) {
				return hashCode(key);
			}
			tmp = tmp->next;
		}
	}
	throw("Table have not this key");
}

void HashTable::clear() const
{
	for (int i = 0; i < getSize(); i++) {
		delete Nodes[i];
	}
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
	const double a = -(1 - sqrt(5) / 2); // константа 
	int size = getSize(); // длина вектора значений
	int N = size + (size % 10); // –азмер таблицы
	return fmod(fmod(key, N) * a * N, N);
}

void HashTable::insert(int key)
{
	Node* tmp = Nodes.at(hashCode(key)); // index = hashCode
	if (tmp == NULL) {
		tmp = new Node(key);
		return;
	}
	
	while (tmp != nullptr) {
		if (tmp->next == nullptr) {
			tmp->next == new Node(key);
			return;
		}
		tmp = tmp->next;
	}
}

void HashTable::insert2(int key)
{
	Node* tmp = Nodes.at(hashCode(key));
	if (tmp == NULL) {
		tmp = new Node(key);
		return;
	}
	for (int i = 0; i < getSize(); i++) {
		if (Nodes[i] == NULL) {
			Nodes[i] = new Node(key);
			tmp->next = Nodes[i];
			return;
		}
	}
}

void HashTable::remove(int key)
{
	Node* tmp = Nodes.at(hashCode(key));
	if (tmp->m_key = key) {
		delete tmp;
		return;
	}
	while (tmp != nullptr) {
		if (tmp->m_key = key) {
			delete tmp;
			return;
		}
		tmp = tmp->next;
	}
}

bool HashTable::searchKey(int key)
{
	Node* tmp = Nodes.at(hashCode(key));
	while (tmp != nullptr) {
		if (tmp->m_key = key) {
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

void HashTable::print()
{
	for (int i = 0; i < getSize(); i++) {
		std::cout << i << ' ';
		Node* tmp = Nodes.at(i);
		while (tmp != nullptr) {
			std::cout << tmp->m_key << ' ';
			tmp = tmp->next;
		}
		std::cout << '\n';
	}
}


