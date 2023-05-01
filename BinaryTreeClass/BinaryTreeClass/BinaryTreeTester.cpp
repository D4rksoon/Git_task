#include "BinaryTreeTester.h"
#include <assert.h>

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

void BinaryTreeTester::check_addAndCount(const BinaryTree* tree, const int size)
{
    assert(tree)
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
    void BinaryTreeTester::remove()
    {
        int invalidKey = -1;
        std::vector<int> nodeKeys;

        BinaryTree* tree = allocateTree();
        tree->removeNode(invalidKey);
        check_remove(tree, nodeKeys.size());

        for (int i = 0; i < m_maxSize; ++i) {
            nodeKeys.push_back(i);
            tree->addNode(i);
        }

        while (!nodeKeys.empty()) {
            int removedNodeIndex = rand() % nodeKeys.size(); //3

            tree->removeNode(invalidKey);
            check_remove(tree, nodeKeys.size());

            tree->removeNode(nodeKeys[removedNodeIndex]);
            nodeKeys.erase(nodeKeys.begin() + removedNodeIndex);
            check_remove(tree, nodeKeys.size());
            if (m_useConsoleOutput)
                tree->print();
        }
        if (m_useConsoleOutput)
            tree->print();
        tree->removeNode(invalidKey);
        check_remove(tree, nodeKeys.size());
        deallocateTree(tree);
    }
}

void BinaryTreeTester::clear()
{
}

void BinaryTreeTester::assign()
{
}

void BinaryTreeTester::height()
{
    height_trivialCases();
    height_longOnlyLeftSubtree();
    height_longOnlyRightSubtree();
    height_longOnlyLeftAndRightSubtrees();
    height_longRandomZigzagSubtrees();
}

void BinaryTreeTester::height_trivialCases()
{
}

void BinaryTreeTester::height_longOnlyLeftSubtree()
{
}

void BinaryTreeTester::height_longOnlyRightSubtree()
{
}

void BinaryTreeTester::height_longOnlyLeftAndRightSubtrees()
{
}

void BinaryTreeTester::height_longRandomZigzagSubtrees()
{
}

