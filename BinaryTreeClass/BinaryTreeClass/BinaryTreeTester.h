#pragma once
#include <Assert.h>
#include <queue>
#include "BinaryTree.h"
class BinaryTreeTester
{
public:
    BinaryTreeTester(const bool useConsoleOutput);
    //BinaryTreeTester() = default;
    ~BinaryTreeTester() = default;

	void test(const int size);

protected:
    virtual BinaryTree* allocateTree();

    virtual void check_addAndCount(const BinaryTree* tree, const int size);
    virtual void check_remove(const BinaryTree* tree, const int size);
    virtual void check_clear(const BinaryTree* tree, const int size);
    virtual void check_assign(const BinaryTree* tree, const int size);
    void check_height(const BinaryTree& tree, const int size);
    void check_copy(BinaryTree* tree1, BinaryTree* tree2);

private:
    void deallocateTree(BinaryTree* tree);

    void addAndCount();
    void destructor();
    void remove();
    void clear();
    void assign(); 
    void height();
    void height_trivialCases();
    void height_longOnlyLeftSubtree();
    void height_longOnlyRightSubtree();
    void height_longOnlyLeftAndRightSubtrees();
    void height_longRandomZigzagSubtrees();
    void treeNodes(std::vector<BinaryTree::Node*>& keys, BinaryTree::Node* root);

private:
    int m_maxSize;
    bool m_useConsoleOutput;

};

