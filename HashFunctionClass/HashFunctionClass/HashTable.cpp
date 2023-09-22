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
	Nodes.resize(m_size);

	for (int i = 0; i < m_size; i++) {
		//int k = other.Nodes[i]->key();
		//std::string v = other.Nodes[i]->value();
		//Nodes[i] = other.Nodes[i];
		Nodes[i] = new Node(other.Nodes[i]->key(), other.Nodes[i]->value());

		/*while (other.Nodes[i]->next != nullptr) {
			this->insert(other.Nodes[i]->setKey(), other.Nodes[i]->setValue());
			tmp = tmp->next;
		}
		Nodes[i] = other.Nodes[i];*/
	}
}

HashTable::~HashTable()
{
	for (Node* node : Nodes) {
		delete node;
	}
	//delete Nodes;

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
	//int hashCode2 = fmod(fmod(key, N) * a * N, N);
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
				if (tmp->key() == key) {
					prev->next = tmp->next; // !!! TODO
					delete tmp;
				}
				prev = tmp;
				tmp = tmp->next;
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
	std::cout << "HashTable - size" << getSize() << '\n';
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
			//Открытая адресация | внутрении цепочки
			keys.push_back(node->key());
		}
			
		//Внешнии цепочки
		while (node != nullptr) {
			keys.push_back(node->key());
			node = node->next;
		}
		
	}
	return keys;
}



// test (сдулать тесты)

