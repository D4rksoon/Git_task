#include <iostream>
#include "BinaryTree.h"

int main()
{
    setlocale(0, "");
    srand(time(0));

    BinaryTree tree;
    tree.root()->setKey(10);   
    for (int i = 1; i <= 6; i++) {
        tree.addNode(i);
    }
    tree.horizontalOutputTree(tree.root());
    //tree.deleteNode(tree.root(), 10);
    std::cout << "\n---------------------\n";
    //tree.horizontalOutputTree(tree.root());
    int height = tree.heightTree(tree.root());
    std::cout << "height: " << height;
    
}
