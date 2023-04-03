#include <iostream>
#include "BinaryTree.h"

int main()
{
    setlocale(0, "");
    srand(time(0));

    BinaryTree tree;
    BinaryTree tree1;
    tree.root()->setKey(10);   
    for (int i = 1; i <= 6; i++) {
        tree.addNode(i);
    }
    tree.horizontalOutputTree(tree.root());

    /*if (tree.deleteNode(tree.root(), 1)) {
        std::cout << "Удаление успешно ";
    }
    else
        std::cout << "Не успешно";*/
    std::cout << "\n---------------------\n";

    //tree.travelNLR(tree.root());
    
    BinaryTree treeC(tree);
    treeC.horizontalOutputTree(treeC.root());

    //tree1 = tree;
    //tree1.horizontalOutputTree(tree1.root());
    
    //int height = tree.heightTree(tree.root());
    //std::cout << "height: " << height;
    
}
