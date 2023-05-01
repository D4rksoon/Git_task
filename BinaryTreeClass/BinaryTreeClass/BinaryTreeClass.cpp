#include <iostream>
#include "BinaryTree.h"
#include "BinaryTreeTester.h"

int main()
{
    setlocale(0, "");
    //srand(time(0));

    BinaryTree tree;
    BinaryTree tree1;
    tree.root()->setKey(10);
    for (int i = 1; i <= 10; i++) {
        tree.addNode(i);
    }
    tree.horizontalOutputTree(tree.root());

    std::cout << "\n---------------------\n";

    //tree.printKey(tree.root());

    if (tree.deleteNode(tree.root(), 2)) {
        std::cout << "Complite " << '\n';
        tree.horizontalOutputTree(tree.root());
    }

    
    //BinaryTree treeC(tree);
    //BinaryTree treeC = tree;
    //treeC.horizontalOutputTree(treeC.root());

    //std::cout << "\n---------------------\n";  

    /*std::vector<int> keys;
    tree.allKeys(keys, tree.root());
    for (int i = 0; i < keys.size(); i++) {
        std::cout << keys[i] << ' ';
    }
    int count = tree.countNode(tree.root());
    std::cout << "\nCount " << count <<"\n";*/

    /*if (tree.deleteNode(tree.root(), 1)) {
        std::cout << "Удаление успешно ";
    }
    else
        std::cout << "Не успешно";*/

    //tree.travelNLR(tree.root());
    


    //tree1 = tree;
    //tree1.horizontalOutputTree(tree1.root());
    
    //int height = tree.heightTree(tree.root());
    //std::cout << "height: " << height;

    BinaryTreeTester tester;
    for (int size = 10; size < 50; size += 10) {
        tester.test(size);
    }
}
