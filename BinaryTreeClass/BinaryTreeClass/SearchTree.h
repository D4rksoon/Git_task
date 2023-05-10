#pragma once
#include "BinaryTree.h";
class SearchTree : public BinaryTree
{
public:
	~SearchTree() override = default;
	using BinaryTree::Node;
	Node* addNode(Node* root, int key) override;
	Node* addNode(int key);

};

