#include "BinaryTree.h"
#include <random>
#include <iostream>

BinaryTree::BinaryTree()
{
	m_root = new Node();
}

BinaryTree::~BinaryTree()
{
	delete m_root;
}

BinaryTree::Node* BinaryTree::root()
{
	return m_root;
}

BinaryTree::Node* BinaryTree::addNode(int key)
{
	if (m_root) {
		return addNode(m_root, key);
	}
	else {
		return m_root = new Node(key);
	}

}

BinaryTree::Node* BinaryTree::addNode(Node* root, int key)
{
	if (!root) {
		root = new Node(key);
		return nullptr;
	}
	else if (!root->leftChild()) {
		root->setLeftChild(new Node(key));
		return root->leftChild();
	}
	else if (!root->rightChild()) {
		root->setRightChild(new Node(key));
		return root->rightChild();
	}
	else if (rand() % 2) {
		addNode(root->leftChild(), key);
		return root->leftChild();
	}
	else {
		addNode(root->rightChild(), key);
		return root->rightChild();
	}
}

void BinaryTree::horizontalOutputTree(Node* root, int leftField, int distanceLevel)
{
	if (root == nullptr) {
		return;
	}
	horizontalOutputTree(root->rightChild(), leftField + distanceLevel, distanceLevel);
	std::cout << std::string(leftField, ' ') << root->key() << std::endl;
	horizontalOutputTree(root->leftChild(), leftField + distanceLevel, distanceLevel);

}

