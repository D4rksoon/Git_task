#include "SearchTree.h"

SearchTree::SearchTree(const int key)
{
	if (key == 0) {
		m_root = nullptr;
	}
	else {
		m_root = new Node(key);
	}
}

SearchTree::SearchTree(const SearchTree& other)
{
	m_root = new Node(other.m_root->key());
	copySubTree(other.m_root->leftChild(), m_root, 0); // 0 - leftSubTree
	copySubTree(other.m_root->rightChild(), m_root, 1); // 1 - right
}

//SearchTree& SearchTree::operator=(const SearchTree& other)
//{
//	if (this == &other) {
//		return *this;
//	}
//	this->clear();
//	m_root = new Node(other.m_root->key());
//	copySubTree(other.m_root->leftChild(), m_root, 0);
//	copySubTree(other.m_root->rightChild(), m_root, 1);
//	return *this;
//}

BinaryTree::Node* SearchTree::addNode(Node* root, int key)
{
    if (!root) {
        root = new Node(key);
    }
    else if (key < root->key()) {
        root->setLeftChild(addNode(root->leftChild(), key));
    }
    else {
        root->setRightChild(addNode(root->rightChild(), key));
    }

    return root;
}

BinaryTree::Node* SearchTree::addNode(int key)
{
	return addNode(m_root, key);
}

BinaryTree::Node* SearchTree::searchNode(Node* root, int key)
{
    if (root->key() == key) {
        return root;
    }
    if (root == nullptr) {
        return nullptr;
    }
    if (key < root->key()) {
        searchNode(root->leftChild(), key);
    }
    else {
        searchNode(root->rightChild(), key);
    }
}

BinaryTree::Node* SearchTree::searchParent(Node* root, Node* node)
{
	if (root == node) {
		return nullptr;
	}
	Node* current = root;
	Node* parent = nullptr;      
	while (current != nullptr)
	{
		if (node == current) {
			break;
		}
		parent = current;
		if (root->key() > node->key()){
			current = current->leftChild();
		}
		else {
			current = current->rightChild();
		}	
	}
	return parent;
}

BinaryTree::Node* SearchTree::searchNode(int key)
{
	return searchNode(m_root, key);
}

bool SearchTree::deleteNode(Node* root, int key)
{
    Node* node = searchNode(root, key);
    Node* nodeParent = searchParent(root, node);

	if (node == nullptr) {
		return false;
	}
	// У удаляемого узла - нет потомков
	if (node->leftChild() == nullptr and node->rightChild() == nullptr) {

		delete node;
		return true;
	}
	// У удаляемого узла - один потомок
	else if (node->leftChild() != nullptr and node->rightChild() == nullptr) {

		Node* replacementNode = node->leftChild();

		if (nodeParent->leftChild()->key() == key) {
			delete node;
			nodeParent->setLeftChild(replacementNode);
			return true;

		}
		else {
			delete node;
			nodeParent->setRightChild(replacementNode);
			return true;

		}
	}
	else if (node->rightChild() != nullptr and node->leftChild() == nullptr) {

		Node* replacementNode = node->rightChild();

		if (nodeParent->leftChild()->key() == key) {
			delete node;
			nodeParent->setLeftChild(replacementNode);
			return true;
		}
		else {
			delete node;
			nodeParent->setRightChild(replacementNode);
			return true;
		}
	}
	// У удаляемого узла - 2 потомка
	else if (node->rightChild() != nullptr and node->leftChild() != nullptr) {
		Node* replacementNode = maxNode(node->leftChild());
		if (nodeParent->leftChild()->key() == key) {
			//nodeParent->setLeftChild(nullptr);
			replacementNode->setLeftChild(node->leftChild());
			replacementNode->setRightChild(node->rightChild());
			delete node;
			nodeParent->setLeftChild(replacementNode);
			return true;
		}
		else {
			//nodeParent->setRightChild(nullptr);
			replacementNode->setLeftChild(node->leftChild());
			replacementNode->setRightChild(node->rightChild());
			delete node;
			nodeParent->setRightChild(replacementNode);
			return true;
		}
	}
	return false;
}

bool SearchTree::deleteNode(int key)
{
	return deleteNode(m_root, key);
}

SearchTree& SearchTree::copySubTreeByNode(Node* root)
{
	this->clear();
	m_root = new Node(root->key());
	copySubTree(root->leftChild(), m_root, 0);
	copySubTree(root->rightChild(), m_root, 1);
	return *this;
}

BinaryTree::Node* SearchTree::maxNode(Node* root)
{
	Node* max = root;
	if (root->rightChild()) {
		return maxNode(root->rightChild());
	}
	return max;
}

int SearchTree::maxKey(Node* root)
{
	if (root == nullptr) {
		return -1;
	}
	if (root->rightChild() == nullptr) {
		return root->key();
	}
	maxKey(root->rightChild());
}

int SearchTree::maxKey()
{
	return maxKey(m_root);
}

int SearchTree::minKey(Node* root)
{
	if (root == nullptr) {
		return -1;
	}
	int min = root->key();
	if (root->leftChild()) {
		return minKey(root->leftChild());
	}
	return min;
}

int SearchTree::minKey()
{
	return minKey(m_root);
}

void SearchTree::printKey(Node* root, int key)
{
	Node* node = searchNode(root, key);
	Node* nodeParent = searchParent(root, node);
	std::cout << "Node " << node->key() << '\n';
	std::cout << "Parent " << nodeParent->key() << '\n';
	//std::cout << "Key " << root->key() << '\n';
}




