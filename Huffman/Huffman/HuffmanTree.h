#pragma once 
#include<string> 
#include<list> 


class HuffmanTree
{
protected:
	class Node;
public:
	HuffmanTree() = default;
	~HuffmanTree() = default;
	void build(const std::string& text);
	double encode(Node* root, const std::string encodeText);
	void decode(Node* root, int i, const std::string encodedText);
	void Table(const std::string& text, int* Tab);
	void createAndSortList(const std::string& text, std::list<Node*>& nodes);

	void codePrint(Node* root, const std::string code);
	bool isLeaf(Node* root);
	Node* root();

	void print(std::list<Node*>& nodes);
	void printNode(Node* node);

protected:
	class Node
	{
		friend class HuffmanTree;
	public:
		Node(std::string symbols)
		{
			m_symbols = symbols;
		}
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
		std::string symbols()
		{
			return m_symbols;
		}
		void setSymbols(std::string symbols)
		{
			m_symbols = symbols;
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

