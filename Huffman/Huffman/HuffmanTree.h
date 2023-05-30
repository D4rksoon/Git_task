#pragma once
#include<string>;
#include<vector>;
#include<set>
#include<fstream>
#include<sstream>
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>

class HuffmanTree
{
protected:
	class Node;
public:
	HuffmanTree();
	~HuffmanTree();
	void build(const std::string& text);
	double encode(const std::string& text, std::string& encodedText);
	bool decode(const std::string& encodedText, std::string& decodedText) const;
	void Table(const std::string& text, int Tab[256]);

protected:
	class Node
	{
		friend class HuffmanTree;
	public:
		Node(std::string symbols);
		~Node() = default;
		int frequency() const
		{
			return m_frequency;
		}
		void setFrequency(const int frequency)
		{
			m_frequency = frequency;
		}
		Node* left()
		{
			return m_left;
		}
		void setLeft(Node* newNode)
		{
			m_left = newNode;
		}
		Node* right()
		{
			return m_right;
		}
		void setRight(Node* newNode)
		{
			m_right = newNode;
		}



	private:
		Node* m_left = nullptr;
		Node* m_right = nullptr;
		int m_frequency = 1;	
		std::string m_symbols;
		//std::vector<bool> m_symbols[256];
	};

private:
	Node* m_root = nullptr;


};

