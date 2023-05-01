#include "BinaryTree.h"


int max(int x, int y)
{
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

void BinaryTree::clear()
{
	deleteAllNode(m_root);
}

BinaryTree::Node* BinaryTree::replaceLeaf(Node* root)
{
	bool end = true;
	if (root->rightChild() == nullptr and root->leftChild() == nullptr) {
		end = false;
		return root;
	}
	if (end) {
		replaceLeaf(root->leftChild());
		replaceLeaf(root->rightChild());
		
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
	clear();
}

BinaryTree::BinaryTree(const BinaryTree& other)
{
	m_root = new Node(other.m_root->key());
	copySubTree(other.m_root->leftChild(), m_root, 0); // 0 - leftSubTree
	copySubTree(other.m_root->rightChild(), m_root, 1); // 1 - right
}

void BinaryTree::copySubTree(Node* copiedTree, Node* currentTree, int k)
{
	if (copiedTree == nullptr) {
		return;
	}
	Node* tmp = new Node(copiedTree->key());
	if (k == 0) {
		currentTree->setLeftChild(tmp);
	}
	else {
		currentTree->setRightChild(tmp);
	}

	copySubTree(copiedTree->leftChild(), tmp, 0);
	copySubTree(copiedTree->rightChild(), tmp, 1);
}

BinaryTree& BinaryTree::operator=(const BinaryTree& other)
{
	if (this == &other) {
		return *this;
	}
	this->clear();
	//clear(this->root());
	m_root = new Node(other.m_root->key());
	copySubTree(other.m_root->leftChild(), m_root, 0);
	copySubTree(other.m_root->rightChild(), m_root, 1);
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
	if (!root->leftChild()) {
		root->setLeftChild(new Node(key));
		return root->leftChild();
	}
	else if (!root->rightChild()) {
		root->setRightChild(new Node(key));
		return root->rightChild();
	}
	else if (rand() % 2) {		
		return addNode(root->leftChild(), key);

	}
	else {	
		return addNode(root->rightChild(), key);
	}
}

bool BinaryTree::deleteNode(Node* root, int key) //TODO
{
	Node* node = searchNLR(root, key);
	Node* nodeParent = searchParent(root, node);
	if (node == nullptr) {
		return false;
	}
	// � ���������� ���� - ��� ��������
	if (node->leftChild() == nullptr and node->rightChild() == nullptr) {
		if (nodeParent->leftChild()->key() == key) {
			nodeParent->setLeftChild(nullptr);
		}
		if (nodeParent->rightChild()->key() == key) {
			nodeParent->setRightChild(nullptr);
		}
		delete node;
		return true;
	}
	// � ���������� ���� - ���� �������
	else if (node->leftChild() != nullptr and node->rightChild() == nullptr) {
		Node* replacementNode = node->leftChild();

		if (nodeParent->leftChild()->key() == key) {
			nodeParent->setLeftChild(nullptr);	
			delete node;
			nodeParent->setLeftChild(replacementNode);
			return true;

		}
		else {
			nodeParent->setRightChild(nullptr);
			delete node;
			nodeParent->setRightChild(replacementNode);
			return true;

		}
	}		
	else if (node->rightChild() != nullptr and node->leftChild() == nullptr) {
		Node* replacementNode = node->rightChild();

		if (nodeParent->leftChild()->key() == key) {
			nodeParent->setLeftChild(nullptr);
			delete node;
			nodeParent->setLeftChild(replacementNode);
			return true;
		}
		else {
			nodeParent->setRightChild(nullptr);
			delete node;
			nodeParent->setRightChild(replacementNode);
			return true;	
		}
	}
	// � ���������� ���� - 2 �������
	else if (node->rightChild() != nullptr and node->leftChild() != nullptr) {
		Node* replacementNode = replaceLeaf(node);
		Node* replacementNodeParent = searchParent(node, replacementNode);

		/*std::cout << "ReplNode " << replacementNode->key() << '\n';
		std::cout << "ReplNodeParent " << replacementNodeParent->key() << '\n';
		std::cout << "Node " << node->key() << '\n';
		std::cout << "NodePArent " << nodeParent->key() << '\n';*/


		if (replacementNodeParent->leftChild() == replacementNode) {
			replacementNodeParent->setLeftChild(nullptr);
		}
		else {
			replacementNodeParent->setRightChild(nullptr);
		}

		if (nodeParent->leftChild()->key() == key) {
			nodeParent->setLeftChild(nullptr);
			replacementNode->setLeftChild(node->leftChild());
			replacementNode->setRightChild(node->rightChild());
			delete node;
			nodeParent->setLeftChild(replacementNode);
			return true;
		}
		else {
			nodeParent->setRightChild(nullptr);
			replacementNode->setLeftChild(node->leftChild());
			replacementNode->setRightChild(node->rightChild());
			delete node;
			nodeParent->setRightChild(replacementNode);
			return true;
		}
	}
	
	return false;
}

bool BinaryTree::deleteNode(int key)
{
	deleteNode(m_root, key);
}

void BinaryTree::deleteAllNode(Node* root)
{
	if (root == nullptr)
		return;
	else if (root) {
		deleteAllNode(root->leftChild());
		deleteAllNode(root->rightChild());
		delete root;
	}
}

void BinaryTree::deleteSubNode(Node* root)
{
	deleteAllNode(root);
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
	Node* subTreeSearch = nullptr;
	subTreeSearch = searchNLR(root->leftChild(), key);
	if (!subTreeSearch) {
		subTreeSearch = searchNLR(root->rightChild(), key);
	}	
	return subTreeSearch;
}

BinaryTree::Node* BinaryTree::searchParent(Node* root, Node* node)
{
	if (root == nullptr) {
		throw("Tree is empty");
	}	
	if (node == nullptr) {
		throw("Node is empty");
	}
	if (!root or root->key() == node->key()) {
		return nullptr;
	}
	Node* parent = nullptr;
	if (root->leftChild() == nullptr and root->rightChild() == nullptr) {
		return parent;
	}
	if (root->leftChild()->key() == node->key() or root->rightChild()->key() == node->key()) {
		parent = root;
	}
	if (parent == nullptr) {
		parent = searchParent(root->leftChild(), node);
	}
	if (parent == nullptr) {
		parent = searchParent(root->rightChild(), node);
	}
	return parent;
}

void BinaryTree::printKey(Node* root)
{
	/*Node* replaceNode = root;
	Node* parent = root;
	for (int i = 1; i < 7; i++) {
		replaceNode = searchNLR(root, i);
		parent = searchParent(root, replaceNode);
		std::cout << "KEY Parent " << parent->key() << "\n";
		std::cout << "KEY ReplaceNode " << replaceNode->key() << "\n";
	}
	*/
	Node* tmp = replaceLeaf(root);
	std::cout << "RightLeaf " << tmp->key() << '\n';
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

void BinaryTree::allKeys(std::vector<int>& keys, Node* root)
{
	if (!root)
	{
		return;
	}

	allKeys(keys, root->leftChild());
	keys.push_back(root->key());
	allKeys(keys, root->rightChild());
}

int BinaryTree::countNode(Node* root)
{
	std::vector<int> keys;
	allKeys(keys, root);
	return keys.size();
}

int BinaryTree::size()
{
	return countNode(m_root);
}

int BinaryTree::minKey(Node* root)
{
	std::vector<int> keys;
	allKeys(keys, root);
	int min = keys[0];
	for (int i = 1; i < keys.size(); i++) {
		if (min > keys[i]) {
			min = keys[i];
		}
	}
	return min;
}

int BinaryTree::maxKey(Node* root)
{
	std::vector<int> keys;
	allKeys(keys, root);
	int max = keys[0];
	for (int i = 1; i < keys.size(); i++) {
		if (max < keys[i]) {
			max = keys[i];
		}
	}
	return max;
}

void BinaryTree::leafsTree(std::vector<int>& keys, Node* root)
{
	if (!root)
	{
		return;
	}	
	leafsTree(keys, root->leftChild());
	if (root->leftChild() == nullptr and root->rightChild() == nullptr) {
		keys.push_back(root->key());
	}
	leafsTree(keys, root->rightChild());
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

void BinaryTree::print()
{
	horizontalOutputTree(m_root);
}

