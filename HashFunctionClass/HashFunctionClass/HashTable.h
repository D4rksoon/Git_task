#pragma once
#include<vector>

class HashTable
{
	class Node;

public:
	HashTable(int size);
	HashTable(const HashTable& other);
	HashTable& operator=(const HashTable& other);
	std::vector<Node*> getNodes();
	int operator[](int key);
	~HashTable() = default;
	void clear() const;
	void setSize(const int size);
	int getSize() const;
	int hashCode(int key);
	void insert(int key);
	void insert2(int key);
	void remove(int key);
	bool searchKey(int key);
	void print();



private:
	int m_size;
	std::vector<Node*> Nodes;


protected:
	class Node
	{
		friend class HashTable;
	public:
		Node() = default;
		Node(int key)
		{
			m_key = key;
			next = nullptr;
		}
		~Node() = default;


	private:
		int m_key = NULL;
		Node* next = nullptr;
		
	};




};

