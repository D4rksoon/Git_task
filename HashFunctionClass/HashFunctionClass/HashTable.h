#pragma once
#include<vector>

class HashTable
{
	class Node;

public:
	HashTable(int size);
	~HashTable() = default;
	void setSize(const int size);
	int getSize() const;
	void insert(int key);
	int hashCode(int key);


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

