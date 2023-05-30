#include <iostream>
#include "BinaryTree.h"
#include "SearchTree.h"
#include "BinaryTreeTester.h"
#include "SearchTreeTester.h"


int main()
{
    setlocale(0, "");
    srand(time(0));

    //BinaryTree tree1;
    //BinaryTree tree2;
    //tree2 = tree2.copySubTreeByNode(tree1.root()->leftChild());
    //tree2 = tree1.copySubTreeByNode(tree1.root()->leftChild()); //better


    /*BinaryTreeTester tester(false);
    for (int size = 10; size < 30; size += 10) {
        tester.test(size);
    }*/

    SearchTreeTester tester(false);
    tester.test(40);

    //SearchTree sTree(16);
    //SearchTree sTree1(11);
    //const int N = 6;
    //int value = 0;
    ///*for (int i = 1; i < N; i++) {
    //    value = rand() % 50;
    //    sTree.addNode(value);
    //}*/
    //sTree.addNode(15);
    //sTree.addNode(10);
    //sTree.addNode(5);
    //sTree.addNode(20);
    //sTree.addNode(18);
    //sTree.addNode(22);
    //sTree.addNode(19);
    //sTree.addNode(21);
    //sTree.print();

    //std::cout << "\n---------------------\n";

    //sTree.BinaryTree::deleteNode(16);
    //sTree.print();

    /*sTree.printKey(sTree.root(), 15);
    sTree.printKey(sTree.root(), 10);
    sTree.printKey(sTree.root(), 5);
    sTree.printKey(sTree.root(), 20);
    sTree.printKey(sTree.root(), 18);
    sTree.printKey(sTree.root(), 22);
    sTree.printKey(sTree.root(), 19);
    sTree.printKey(sTree.root(), 21);*/
    //std::cout << "\n---------------------\n";

    //std::cout << "Key " << sTree.searchNode(15)->key() << '\n';
    // 
    //std::cout << "Max " << sTree.maxKey() << '\n';
    //std::cout << "Min " << sTree.minKey() << '\n';

    /*const int N = 6;
    BinaryTree tree(100);
    BinaryTree tree1;
    for (int i = 1; i <= N; i++) {
        tree.addNode(i);
    }
    tree.print();*/
   
    /*for (int i = 1; i <= N; i++) {
        tree.printKeys(tree.root(), i);
    }*/

    //tree.printKeys(tree.root(), 3);

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
