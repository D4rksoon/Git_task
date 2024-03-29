#include "BinaryTreeTester.h"
BinaryTreeTester::BinaryTreeTester(const bool useConsoleOutput)
    : m_useConsoleOutput(useConsoleOutput)
{}

void BinaryTreeTester::test(const int size)
{
	m_maxSize = size;
    addAndCount();
    destructor();
    remove();
    clear();
    assign();
    height();
}

BinaryTree* BinaryTreeTester::allocateTree()
{
    return new BinaryTree;
}

void BinaryTreeTester::deallocateTree(BinaryTree* tree)
{
    delete tree;
}

void BinaryTreeTester::addAndCount()
{
    BinaryTree* tree = allocateTree();
    check_addAndCount(tree, 0);
    for (int i = 0; i < m_maxSize; i++) {
        tree->addNode(i);
        check_addAndCount(tree, i + 1);
    }
    deallocateTree(tree);
}

void BinaryTreeTester::check_addAndCount(const BinaryTree *tree, const int size)
{
    assert(tree->size() == size);
}

void BinaryTreeTester::destructor()
{
    const int runsCount = 200;
    for (int i = 0; i < runsCount; i++)
    {
        BinaryTree* tree = allocateTree();
        for (int i = 0; i < m_maxSize; ++i) {
            tree->addNode(i);
        }
        deallocateTree(tree);
    }
    std::cout << "BinaryTreeTester::destructor ended. Press any key to continue..." << std::endl;
    getchar();
}


void BinaryTreeTester::remove()
{
    int invalidKey = -1;
    std::vector<int> nodeKeys;

    BinaryTree* tree = allocateTree();
    tree->deleteNode(invalidKey);
    check_remove(tree, nodeKeys.size());

    for (int i = 0; i < m_maxSize; ++i) {
        nodeKeys.push_back(i);
        tree->addNode(i);
    }

    while (!nodeKeys.empty()) {
        int removedNodeIndex = rand() % nodeKeys.size(); //3

        tree->deleteNode(invalidKey);
        check_remove(tree, nodeKeys.size());

        tree->deleteNode(nodeKeys[removedNodeIndex]);
        nodeKeys.erase(nodeKeys.begin() + removedNodeIndex);
        check_remove(tree, nodeKeys.size());
        if (m_useConsoleOutput)
            tree->print();
    }
    if (m_useConsoleOutput)
        tree->print();
    tree->deleteNode(invalidKey);
    check_remove(tree, nodeKeys.size());
    deallocateTree(tree);
}

void BinaryTreeTester::check_remove(const BinaryTree* tree, const int size)
{
    assert(tree->size() == size);
}

void BinaryTreeTester::clear()
{
    BinaryTree* tree = allocateTree();
    for (int i = 0; i < 200; i++)
    {
        for (int i = 0; i < m_maxSize; ++i) {
            tree->addNode(i);
        }
        tree->clear();
        check_clear(tree, 0);
    }
    deallocateTree(tree);
    std::cout << "BinaryTreeTester::destructor ended. Press any key to continue..." << std::endl;
    getchar();
}

void BinaryTreeTester::check_clear(const BinaryTree* tree, const int size)
{
    assert(tree->size() == size);
}

void BinaryTreeTester::assign()
{
    BinaryTree* tree1 = allocateTree();
    BinaryTree* tree2 = allocateTree();

    for (int i = 0; i < m_maxSize; ++i) {
        tree1->addNode(i);
    }

    tree2 = tree1; //Конструктор копирования

    check_assign(tree2, m_maxSize);
    check_copy(tree1, tree2);

    deallocateTree(tree1);
    deallocateTree(tree2);
}

void BinaryTreeTester::check_copy(BinaryTree* tree1, BinaryTree* tree2)
{
    std::vector<BinaryTree::Node*> tree1Nodes;
    std::vector<BinaryTree::Node*> tree2Nodes;
    treeNodes(tree1Nodes, tree1->root());
    treeNodes(tree2Nodes, tree1->root());
    assert(tree1Nodes.size() == tree2Nodes.size());
    for (int i = 0; i < m_maxSize; i++) {
        assert(tree1Nodes[i]->key() == tree2Nodes[i]->key());
        assert(tree1Nodes[i] != tree2Nodes[i]);
    }
}
void BinaryTreeTester::treeNodes(std::vector<BinaryTree::Node*>& keys, BinaryTree::Node* root)
{
    if (!root)
    {
        return;
    }

    treeNodes(keys, root->leftChild());
    keys.push_back(root);
    treeNodes(keys, root->rightChild());
}

void BinaryTreeTester::check_assign(const BinaryTree* tree, const int size)
{
    assert(tree->size() == size);

}

void BinaryTreeTester::height()
{
    height_trivialCases();
    height_longOnlyLeftSubtree();
    height_longOnlyRightSubtree();
    height_longOnlyLeftAndRightSubtrees();
    height_longRandomZigzagSubtrees();
}

void BinaryTreeTester::check_height(const BinaryTree& tree, const int height)
{
    assert(tree.height() == height);
}

void BinaryTreeTester::height_trivialCases()
{
    BinaryTree tree;
    check_height(tree, 0);
    tree.addNode(0);
    check_height(tree, 1);
}

void BinaryTreeTester::height_longOnlyLeftSubtree()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node* runner = longTree.root();
    for (int i = 1; i < m_maxSize; ++i) {
        runner->setLeftChild(new BinaryTree::Node(i));
        runner = runner->leftChild();
        check_height(longTree, i + 1);
    }
}

void BinaryTreeTester::height_longOnlyRightSubtree()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node* runner = longTree.root();
    for (int i = 1; i < m_maxSize; ++i) {
        runner->setRightChild(new BinaryTree::Node(i));
        runner = runner->rightChild();
        check_height(longTree, i + 1);
    }
}

void BinaryTreeTester::height_longOnlyLeftAndRightSubtrees()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node* leftRunner = longTree.root();
    BinaryTree::Node* rightRunner = longTree.root();
    for (int i = 1; i < m_maxSize / 2; ++i) {
        leftRunner->setLeftChild(new BinaryTree::Node(i));
        leftRunner = leftRunner->leftChild();
        check_height(longTree, i + 1);


        rightRunner->setRightChild(new BinaryTree::Node(i));
        rightRunner = rightRunner->rightChild();
        check_height(longTree, i + 1);
    }
}

void BinaryTreeTester::height_longRandomZigzagSubtrees()
{
    BinaryTree longTree;
    longTree.addNode(0);
    BinaryTree::Node* leftRunner = longTree.root();
    BinaryTree::Node* rightRunner = longTree.root();

    leftRunner->setLeftChild(new BinaryTree::Node(1));
    leftRunner = leftRunner->leftChild();
    rightRunner->setRightChild(new BinaryTree::Node(1));
    rightRunner = rightRunner->rightChild();

    for (int i = 2; i < m_maxSize / 2; ++i) {
        if (rand() % 2 == 0)
        {
            leftRunner->setLeftChild(new BinaryTree::Node(i));
            leftRunner = leftRunner->leftChild();
        }
        else
        {
            leftRunner->setRightChild(new BinaryTree::Node(i));
            leftRunner = leftRunner->rightChild();
        }
        check_height(longTree, i + 1);

        if (rand() % 2 == 0)
        {
            rightRunner->setLeftChild(new BinaryTree::Node(i));
            rightRunner = rightRunner->leftChild();
        }
        else
        {
            rightRunner->setRightChild(new BinaryTree::Node(i));
            rightRunner = rightRunner->rightChild();
        }
        check_height(longTree, i + 1);
    }
}



