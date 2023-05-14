#include <iostream>
#include "BinaryTree.h"
#include "SearchTree.h"
#include "BinaryTreeTester.h"


int main()
{
    setlocale(0, "");
    srand(time(0));

    /*BinaryTreeTester tester;
    for (int size = 10; size < 30; size += 10) {
        tester.test(size);
    }*/

    SearchTree sTree(16);
    SearchTree sTree1(11);
    const int N = 6;
    int value = 0;
    for (int i = 1; i < N; i++) {
        value += 5;
        sTree.addNode(value);
    }
    sTree.print();

    std::cout << "\n---------------------\n";


    //std::cout << "Max " << sTree.maxKey() << '\n';
    //std::cout << "Min " << sTree.minKey() << '\n';

    /*const int N = 6;
    BinaryTree tree(100);
    BinaryTree tree1;
    for (int i = 1; i <= N; i++) {
        tree.addNode(i);
    }
    tree.print();*/

    std::cout << "\n---------------------\n";
    



    //tree.printKey(tree.root());

    /*if (tree.deleteNode(2)) {
        std::cout << "Complite " << '\n';
        tree.print();
    }*/

    /*int level = 1;
    int c = 0;
    for (int i = 1; i <= N; i++) {
        c = i;
        std::cout << c << "] LevelKeys " << tree.heightKey(i) << '\n';

    }*/

    /*if (tree.isBalanceTree() {
        std::cout << "itsBalanseTree!!! ";
    }*/
    
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
    
    //int height = tree.height();
    //std::cout << "height: " << height << '\n';

}
