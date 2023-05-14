#pragma once
#include "BinaryTree.h";
class SearchTree : public BinaryTree
{
	using BinaryTree::Node;

protected:
	Node* addNode(Node* root, int key) override;
	Node* searchNode(Node* root, int key);
	bool deleteNode(Node* root, int key) override;
	int maxKey(Node* root);
	int minKey(Node* root);

public:
	SearchTree(const int key = 0);
	SearchTree(const SearchTree& other);
	SearchTree& operator= (const SearchTree&);
	~SearchTree() override = default;
	Node* addNode(int key);
	bool deleteNode(int ley);
	SearchTree& copySubTreeByNode(Node* root);
	Node* searchNode(int key);
	int maxKey();
	int minKey();

};

