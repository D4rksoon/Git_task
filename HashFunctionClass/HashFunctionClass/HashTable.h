#pragma once
#include<vector>
#include<string>

class HashTable
{
	class Node;

public:
	HashTable(int size = 0);
	HashTable(const HashTable& other);
	HashTable& operator=(const HashTable& other);
	std::vector<Node*> getNodes();
	std::string& operator[](int key);
	~HashTable();
	void clearTable();
	int getSize() const;
	int hashCode(int key);
	void insert(int key, std::string value);
	void insert_old(int key, std::string value);	
	void remove(int key);
	bool searchKey(int key);
	void print();
	std::vector<int> keys();

	void remove_old(int key);
private:
	int m_size;
	std::vector<Node*> Nodes;

protected:
	class Node
	{
		friend class HashTable;
	public:
		Node() = default;
		Node(int key, std::string value)
		{
			m_key = key;
			m_value = value;
			next = nullptr;
		}
		~Node() = default;
		int key()
		{
			return m_key;
		}
		void setKey(int key)
		{
			m_key = key;
		}
		std::string value()
		{
			return m_value;
		}
		void setValue(std::string value)
		{
			m_value = value;
		}


	private:
		int m_key = 0;
		std::string m_value;
		Node* next = nullptr;
		
	};




};

