#pragma once
#include <vector>
#include <random>
#include <iostream>
class BinaryTree
{
	friend class BinaryTreeTester;
	friend class SearchTree;

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
		Node* leftChild()
		{
			return m_leftChild;
		}
		const Node* leftChild() const
		{
			return m_leftChild;
		}
		void setLeftChild(Node* newChild)
		{
			m_leftChild = newChild;
		}
		Node* rightChild()
		{
			return m_rightChild;
		}
		const Node* rightChild() const
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
		friend class BinaryTree;
	};
protected:
	Node* replaceLeaf(Node* root);
	virtual Node* addNode(Node* root, int key);
	virtual bool deleteNode(Node* root, int key);
	void deleteAllNode(Node* root);
	Node* searchNLR(Node* root, int key);
	Node* searchParent(Node* root, Node* node);
	int heightTree(Node* root) const;
	int heightKey(Node* root, int key, int level);
	bool isBalanceTree(Node* root);
	void allKeys(std::vector<int>& keys, Node* root) const;
	int size(Node* root) const;
	int minKey(Node* root);
	int maxKey(Node* root);
	int sumKeys(Node* root);
	void horizontalOutputTree(Node* root, int leftField = 0, int distanceLevel = 8);
	void copySubTree(Node* copiedTree, Node* currentTree, int k);
	void leafsTree(std::vector<int>& keys, Node* root);
	void travelNLR(Node* root);

public:
	BinaryTree(const int key = 0);
	virtual ~BinaryTree();
	BinaryTree(const BinaryTree& other);
	BinaryTree& operator=(const BinaryTree&);
	BinaryTree& copySubTreeByNode(Node* root);
	Node* root();
	const Node* root() const;
	Node* addNode(int key);
	bool deleteNode(int key);
	void clear();
	bool isEmpty();
	Node* searchNLR(int key);
	int height() const;
	int heightKey(int key);
	bool isBalanceTree();
	std::vector<int> allKeys() const;
	int size() const;
	int minKey();
	int maxKey();
	int sumKeys();
	std::vector<int> leafsTree();
	void print();

private:
	Node* m_root = nullptr;

};

