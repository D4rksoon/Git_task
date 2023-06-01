#pragma once
#include "BinaryTree.h";
class SearchTree : public BinaryTree
{
	using BinaryTree::Node;
protected:
	Node* addNode(Node* root, int key) override;
	Node* searchNode(Node* root, int key);
	Node* searchParent(Node* root, Node* node) override;
	bool deleteNode(Node* root, int key) override;
	Node* maxNode(Node* root);
	int maxKey(Node* root) override;
	int minKey(Node* root) override;

public:
	SearchTree() = default;
	SearchTree(const int key);
	SearchTree(const SearchTree& other) = default;
	SearchTree& operator= (const SearchTree&) = default;
	~SearchTree() override = default;
	SearchTree copySubTreeByNode(Node* root) const;
	Node* searchNode(int key);
	void printKey(Node* root, int key);
	using BinaryTree::addNode;
	using BinaryTree::deleteNode;
	using BinaryTree::maxKey;
	using BinaryTree::minKey;

	static SearchTree buildOptimalTree(const std::vector<int>& keys,
		const std::vector<int> &keysFrequences,
		const std::vector<int> &nonKeysFrequences );
};

