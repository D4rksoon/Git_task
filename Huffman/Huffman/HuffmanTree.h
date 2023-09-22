#pragma once
<<<<<<< Updated upstream
=======
<<<<<<< Updated upstream
>>>>>>> Stashed changes
#include<string>;
#include<vector>;
#include<set>
#include<fstream>
#include<sstream>
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>
<<<<<<< Updated upstream
=======
=======
#include<string>
#include<list>

>>>>>>> Stashed changes
>>>>>>> Stashed changes

class HuffmanTree
{
protected:
	class Node;
public:
<<<<<<< Updated upstream
=======
<<<<<<< Updated upstream
>>>>>>> Stashed changes
	HuffmanTree();
	~HuffmanTree();
	void build(const std::string& text);
	double encode(const std::string& text, std::string& encodedText);
	bool decode(const std::string& encodedText, std::string& decodedText) const;
	void Table(const std::string& text, int Tab[256]);
<<<<<<< Updated upstream
=======
=======
	HuffmanTree() = default;
	~HuffmanTree() = default;
	void build(const std::string& text);
	void encode(Node* root, const std::string encodeText);
	bool decode(const std::string& encodedText, std::string& decodedText) const;
	void Table(const std::string& text, int *Tab);
	void createAndSortList(const std::string& text, std::list<Node*>& nodes);
	
	void codePrint(Node* root, const std::string code);
	bool isLeaf(Node* root);

	void print(std::list<Node*>& nodes);
	void printNode(Node* node);
>>>>>>> Stashed changes
>>>>>>> Stashed changes

protected:
	class Node
	{
		friend class HuffmanTree;
	public:
<<<<<<< Updated upstream
		Node(std::string symbols);
=======
<<<<<<< Updated upstream
		Node(std::string symbols);
=======
		Node(std::string symbols)
		{
			m_symbols = symbols;
		}
>>>>>>> Stashed changes
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream

=======
<<<<<<< Updated upstream

=======
		std::string symbols()
		{
			return m_symbols;
		}
		void setSymbols(std::string symbols)
		{
			m_symbols = symbols;
		}
>>>>>>> Stashed changes
>>>>>>> Stashed changes


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

