#include "BinaryTreeTester.h"

class SearchTreeTester : public BinaryTreeTester
{
public:
    SearchTreeTester(const bool useConsoleOutput);
    ~SearchTreeTester() = default;

protected:
    BinaryTree* allocateTree() override;
    void check_addAndCount(const BinaryTree* tree, const int size) override;
    void check_remove(const BinaryTree* tree, const int size) override;
    void check_clear(const BinaryTree* tree, const int size) override;
    void check_assign(const BinaryTree* tree, const int size) override;


    bool isSearchTree(const BinaryTree* tree)
    {
        std::vector<int> keys;
        getKeysLnr(keys, tree->root());
        for (int i = 1; i < keys.size(); i++)
        {
            if (keys[i] <= keys[i - 1])
            {
                return false;
            }
        }
        return true;
    }
    void getKeysLnr(std::vector<int>& keys, const BinaryTree::Node* node)
    {
        if (!node)
        {
            return;
        }

        getKeysLnr(keys, node->leftChild());
        keys.push_back(node->key());
        getKeysLnr(keys, node->rightChild());
    }
};
