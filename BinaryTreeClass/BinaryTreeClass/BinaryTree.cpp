#include "BinaryTree.h"
#include <random>
#include <iostream>

int max(int x, int y)
{
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

void BinaryTree::clear(Node* root)
{
	if (root == nullptr)
		return;
	else if (root) {
		clear(root->leftChild());
		clear(root->rightChild());
		delete root;
	}
}

BinaryTree::BinaryTree()
{
	m_root = new Node();
}

BinaryTree::~BinaryTree()
{
	delete m_root;
}

BinaryTree::BinaryTree(const Node& other)
{
	m_root = new Node(other.key());
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

bool BinaryTree::deleteNode(Node* root, int key)
{
	if (root->key() == key) {
		Node* del = root;
		if (root->leftChild() == 0 and root->rightChild() == 0) {
			delete root;
		}
		else if (root->leftChild() == 0) {
			root = root->rightChild();
			delete root;
		}
		else {
			root = root->rightChild();
			delete root;
		}
		return true;
	}
	else {
		deleteNode(root->leftChild(), key);
		deleteNode(root->rightChild(), key);
	}
	return false;
}

void BinaryTree::deleteAllNode(Node* root)
{
	clear(root);
}

bool BinaryTree::isEmpty()
{
	Node* tmp = m_root;
	if (m_root == nullptr) {
		return true;
	}
	else
		return false;
}

int BinaryTree::heightTree(Node* root)
{
	if (root->leftChild() == nullptr and root->rightChild() == nullptr) {
		return 1;
	}
	else {
		//int r = heightTree(root->rightChild());
		//int l = heightTree(root->leftChild());
		if (root->leftChild() == nullptr) {
			return 1 + heightTree(root->rightChild());
		}
		else if (root->rightChild() == nullptr) {
			return 1 + heightTree(root->leftChild());
		}
		else {
			return 1 + max(heightTree(root->leftChild()), heightTree(root->rightChild()));
		}
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

