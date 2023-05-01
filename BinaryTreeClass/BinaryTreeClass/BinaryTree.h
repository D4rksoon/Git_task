#pragma once
#include <vector>
#include <random>
#include <iostream>
class BinaryTree
{
	friend class BinaryTreeTester;
	class Node // private
	{
	public:
		Node(int key = 0, Node* leftChild = nullptr, Node* rightChild = nullptr)
		{
			m_key = key;
			m_leftChild = leftChild;
			m_rightChild = rightChild;
		}
		~Node() = default;
		int key() const
		{
			return m_key;
		}
		void setKey(const int key)
		{
			m_key = key;
		}
		Node* leftChild() const
		{
			return m_leftChild;
		}
		void setLeftChild(Node* newChild)
		{
			m_leftChild = newChild;
		}
		Node* rightChild() const
		{
			return m_rightChild;
		}
		void setRightChild(Node* newChild)
		{
			m_rightChild = newChild;
		}


	private:
		int m_key = 0;
		Node* m_leftChild;
		Node* m_rightChild;
	};
protected:
	Node* replaceLeaf(Node* root);
	Node* addNode(Node* root, int key);
	bool deleteNode(Node* root, int key);
	void deleteAllNode(Node* root);
	Node* searchNLR(Node* root, int key);
	Node* searchParent(Node* root, Node* node);
	int heightTree(Node* root);
	void allKeys(std::vector<int>& keys, Node* root);
	int size(Node* root);
	int minKey(Node* root);
	int maxKey(Node* root);
	void horizontalOutputTree(Node* root, int leftField = 0, int distanceLevel = 8);
	void copySubTree(Node* copiedTree, Node* currentTree, int k);
	void leafsTree(std::vector<int>& keys, Node* root);
	void travelNLR(Node* root);

public:
	BinaryTree(const int key = 0);
	~BinaryTree();
	BinaryTree(const BinaryTree& other);
	BinaryTree& operator=(const BinaryTree&);
	Node* root();
	Node* addNode(int key);
	bool deleteNode(int key);
	void clear();
	bool isEmpty();
	Node* searchNLR(int key);
	void printKey(Node* root);
	int height();
	std::vector<int> allKeys();
	int size();
	int minKey();
	int maxKey();
	std::vector<int> leafsTree();
	void print();

private:
	Node* m_root = nullptr;

};

