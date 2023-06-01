#include "SearchTree.h"
#include <vector>

SearchTree::SearchTree(const int key) : BinaryTree(key)
{}

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

BinaryTree::Node* SearchTree::searchNode(Node* root, int key)
{
	if (root == nullptr) {
		return nullptr;
	}
    if (root->key() == key) {
        return root;
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
	if (node == nullptr) {
		return false;
	}
    Node* nodeParent = searchParent(root, node);

	
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
		Node* replacementNode = maxNode(node->leftChild()); // Если у заменяемого узла есть потомк
		Node* replacementNodeParent = searchParent(node, replacementNode);
		replacementNodeParent->setRightChild(replacementNode->leftChild());
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

SearchTree SearchTree::copySubTreeByNode(Node* root) const
{
	SearchTree subTree(root->key());
	copySubTree(root->leftChild(), subTree.root(), false);
	copySubTree(root->rightChild(), subTree.root(), true);
	return subTree;
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
		throw("Tree is empty");
	}
	if (root->rightChild() == nullptr) {
		return root->key();
	}
	maxKey(root->rightChild());
}

int SearchTree::minKey(Node* root)
{
	if (root == nullptr) {
		throw("Tree is empty");
	}
	int min = root->key();
	if (root->leftChild()) {
		return minKey(root->leftChild());
	}
	return min;
}

void SearchTree::printKey(Node* root, int key)
{
	Node* node = searchNode(root, key);
	Node* nodeParent = searchParent(root, node);
	std::cout << "Node " << node->key() << '\n';
	std::cout << "Parent " << nodeParent->key() << '\n';
	//std::cout << "Key " << root->key() << '\n';
}

SearchTree SearchTree::buildOptimalTree(const std::vector<int>& keys, 
		const std::vector<int>& keysFrequences,
		const std::vector<int>& nonKeysFrequences)
{
	//const int size = keys.size();
	//std::vector<std::vector<int>> matrW(size);
	//std::vector<std::vector<int>> matrC;
	//std::vector<std::vector<int>> matrR;
	//for (int i = 0; i < size; i++) {
	//	matrW[i].resize(size);
	//}

	//const int size = nonKeysFrequences.size();
	//int** matrW = new int* [size];
	//int** matrC = new int* [size];
	//int** matrR = new int* [size];
	//for (int i = 0; i < size; i++) {
	//	//matrW[i] = matr[];
	//	matrC[i] = new int[size];
	//	matrR[i] = new int[size];
	//}

	//for (int i = 0; i < size; i++) {
	//	matrW[i][i] = nonKeysFrequences[i];
	//	matrC[i][i] = nonKeysFrequences[i];
	//}
	//for (int i = 0, j = 1; i < size; i++, j++) {
	//	matrW[i][j] = matrW[i][i] + keysFrequences[i] + nonKeysFrequences[j];
	//	matrC[i][j] = matrW[i][j] + matrC[i][i] + matrC[j][j];
	//	matrR[i][j];
	//}

	return SearchTree();
}




