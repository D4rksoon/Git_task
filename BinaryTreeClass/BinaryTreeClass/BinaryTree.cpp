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

void BinaryTree::travelNLR(Node* root)
{
	if (root == nullptr) {
		return;
	}
	std::cout << root->key() << ' ';

	travelNLR(root->leftChild());
	travelNLR(root->rightChild());
}

BinaryTree::BinaryTree(const int key)
{
	m_root = new Node(key);
}

BinaryTree::~BinaryTree()
{
	clear(m_root);
}

BinaryTree::BinaryTree(const Node& other)
{
	m_root = new Node(other.key());
}

BinaryTree& BinaryTree::operator=(const BinaryTree& other)
{
	if (this == &other) {
		return *this;
	}
	clear(this->root());
	m_root = new Node(other.m_root->key());
	m_root->setLeftChild(other.m_root->leftChild());
	m_root->setRightChild(other.m_root->rightChild());
	return *this;
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

bool BinaryTree::deleteNode(Node* root, int key) //TODO
{
	/*if (!root or root->key() == key) {
		delete root;		
		return true;
	}*/
	root = searchNLR(root, key);
	if (root->leftChild() == nullptr and root->rightChild() == nullptr) {

		delete root;
		return true;
	}
	else if (root->leftChild() == nullptr) {

	}
	//deleteNode(root->leftChild(), key);
	//deleteNode(root->rightChild(), key);
	
	return false;
}

void BinaryTree::deleteAllNode(Node* root)
{
	clear(root);
}

bool BinaryTree::isEmpty()
{
	Node* tmp = m_root;
	if (tmp == nullptr) {
		return true;
	}
	else
		return false;
}

BinaryTree::Node* BinaryTree::searchNLR(Node* root, int key)
{
	if (!root or root->key() == key) {
		return root;
	}
	Node* subSearch = searchNLR(root->leftChild(), key);
	if (!subSearch) {
		subSearch = searchNLR(root->rightChild(), key);
	}
	return subSearch;
}

int BinaryTree::heightTree(Node* root)
{
	if (root->leftChild() == nullptr and root->rightChild() == nullptr) {
		return 1;
	}
	else {
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

