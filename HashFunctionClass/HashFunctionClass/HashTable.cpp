#include "HashTable.h"
#include<vector>
#include<iostream>

HashTable::HashTable(int size) :
	m_size(size + 1),
	Nodes(m_size, nullptr)
{}

HashTable::HashTable(const HashTable& other)
{
	m_size = other.m_size;
	//Nodes.resize(m_size);
	for (int i = 0; i < Nodes.size(); i++) {
		delete Nodes[i];
		Nodes[i] = nullptr;
	}
	for (int i = 0; i < other.getSize(); i++) {
		Node* newNode = new Node();
		if (other.Nodes[i]) {
			newNode->m_key = other.Nodes[i]->m_key;
			newNode->m_value = other.Nodes[i]->m_value;
		}
		else {
			newNode = nullptr;
		}
		Nodes.push_back(newNode);
	}
	for (int i = 0; i < other.getSize(); i++) {

		Node* tmp = other.Nodes[i];
		while (tmp != nullptr) {
			if (tmp->next) {
				Nodes[i]->next == tmp;
			}
			tmp = tmp->next;
		}

	}
	/*for (int i = 0; i < other.getSize(); i++) {
		Node* newNode = new Node();
		if (other.Nodes[i]) {
			newNode->m_key = other.Nodes[i]->m_key;
			newNode->m_value = other.Nodes[i]->m_value;
			int j = 0;
			Node* tmp = other.Nodes[i];
			while (tmp->next != nullptr) {
				if (other.Nodes[j]->next == nullptr) {
					newNode->next = other.Nodes[j];
				}
				tmp = tmp->next;
				j++;
			}
		}
		
		Nodes[i] = other.Nodes[i];
	}*/
}

HashTable::~HashTable()
{
	for (Node* node : Nodes) {
		delete node;
	}
}

HashTable& HashTable::operator=(const HashTable& other)
{
	if (this == &other) {
		return *this;
	}
	this->clearTable();
	HashTable table(other.getSize());

	return table;
}

std::vector<HashTable::Node*> HashTable::getNodes()
{
	return Nodes;
}

std::string& HashTable::operator[](int key)
{
	std::string v;
	int index = hashCode(key);
	Node* tmp = Nodes[index];
	while (tmp) {
		if (tmp->key() == key) {
			v = tmp->value();
			return v;
		}
		tmp = tmp->next;
	}
}

void HashTable::clearTable()
{
	for (int i = 0; i < getSize(); i++) {
		delete Nodes[i];
		Nodes[i] = nullptr;
	}
}

int HashTable::getSize() const
{
	return m_size;
}

int HashTable::hashCode(int key)
{
	const double a = -(1 - sqrt(5)) / 2; // const a = 0.618034
	int N = getSize(); // Table size
	int hashCode = int((key % N) * a * N) % N;
	return hashCode;
}

void HashTable::insert_old(int key, std::string value)
{
	int index = hashCode(key);
	Node* newNode = new Node(key, value);
	if (Nodes[index] == NULL) {
		Nodes[index] = newNode;
		return;
	}	
	Node* tmp = Nodes[index];
	while (tmp != nullptr) {
		if (tmp->next == nullptr) {
			tmp->next = newNode;
			return;
		}
		tmp = tmp->next;
	}
}

void HashTable::insert(int key, std::string value)
{
	int index = hashCode(key);
	Node* newNode = new Node(key, value);
	if (Nodes[index] == NULL) {
		Nodes[index] = newNode;
		return;
	}
	else {
		Node* tmp = Nodes[index];
		for (int i = 0; i < getSize(); i++) {
			if (Nodes[i] == NULL) {
				Nodes[i] = newNode;
				while (tmp->next) {
					tmp = tmp->next;
				}
				tmp->next = newNode;
				return;
			}
		}
		std::cerr << "Error: Table is full\n";
	}
}

void HashTable::insertTest(int key, std::string value)
{
	int index = hashCode(key);
	Node* newNode = new Node(key, value);
	if (Nodes[index] == NULL) {
		Nodes[index] = newNode;
		return;
	}
	else {
		Node* tmp = Nodes[index];
		for (int i = 0; i < getSize(); i++) {
			if (Nodes[i] == NULL) {
				Nodes[i] = newNode;
				while (tmp->next) {
					tmp = tmp->next;
				}
				tmp->next = newNode;
				return;
			}		
		}		
		std::cerr << "Error: Table is full\n";
	}
}

void HashTable::deleteTest(int key)
{
	int index = hashCode(key);
	Node* tmp = Nodes[index];
	if (tmp == NULL) {
		return; // If key does not exist
	}
	// No collision
	if (tmp->next == nullptr and tmp->key() == key) {
		Nodes[index] = NULL;
		delete tmp;
		return;
	}
	// If does collision
	else if (tmp->next != nullptr){
		if (tmp->key() == key) {
			Nodes[index] = tmp->next;
			if (tmp->next->next) {
				Nodes[index]->next = tmp->next->next;
			}
			delete tmp->next;
			return;
		}
		else {
			Node* prev = nullptr;
			while (tmp) {
				if (tmp->key() == key) {
					prev->next = tmp->next;
					delete tmp;
				}
				prev = tmp;
				tmp = tmp->next;
			}
		}
	}

}

void HashTable::remove(int key)
{
	int index = hashCode(key);
	Node* tmp = Nodes[index];
	if (tmp == NULL) {
		return; // If key does not exist
	}
	// No collision
	if (tmp->next == nullptr and tmp->key() == key) {
		Nodes[index] = NULL;
		delete tmp;
		return;
	}
	// If does collision
	else if (tmp->next != nullptr) {
		if (tmp->key() == key) {
			Nodes[index] = tmp->next;
			if (tmp->next->next) {
				Nodes[index]->next = tmp->next->next;
			}
			delete tmp->next;
			return;
		}
		else {
			Node* prev = nullptr;
			while (tmp) {
				if (tmp->key() == key and prev != nullptr) {
					prev->next = tmp->next; 
					delete tmp;
				}
				else{
					prev = tmp;
					tmp = tmp->next;
				}
				
			}
		}
	}
}

bool HashTable::searchKey(int key)
{
	int index = hashCode(key);
	Node* tmp = Nodes[index];
	while (tmp) {
		if (tmp->key() == key) {
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

void HashTable::print()
{
	std::cout << "HashTable size - " << getSize() - 1 << '\n';
	for (int i = 0; i < getSize(); i++) {
		if (Nodes[i]) {
			std::cout << "[" << i << "] Hash: " << hashCode(Nodes[i]->key());
			std::cout << " Key: " << Nodes[i]->key();
			std::cout << " Value: " << Nodes[i]->value() << '\n';
		}
	}
}

std::vector<int> HashTable::keys()
{
	std::vector<int> keys;
	for (Node* node : Nodes) {
		if (node) {
			//�������� ��������� | ��������� �������
			keys.push_back(node->key());
		}
			
		//������� �������
		while (node != nullptr) {
			keys.push_back(node->key());
			node = node->next;
		}
		
	}
	return keys;
}



// test (������� �����)

