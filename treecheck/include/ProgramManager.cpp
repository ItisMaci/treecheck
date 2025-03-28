#include "ProgramManager.h"

ProgramManager::ProgramManager(){}

void ProgramManager::treecheck(std::string file)
{
    ClearScreen();
    BinaryTree tree;
    Import(tree, file);
    std::cout << "\nAVL-Check" << std::endl;
    Stats(tree);
    PauseScreen();
}

void ProgramManager::treecheck(std::string file1, std::string file2)
{
    ClearScreen();
    Search(file1, file2);
    PauseScreen();
}

void ProgramManager::ClearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void ProgramManager::PauseScreen()
{
    std::cout << "\n\nPress Enter to continue..." << std::endl;
    std::cin.clear();
    std::cin.get();
}

void ProgramManager::Import(BinaryTree& tree, std::string file)
{
    if(tree.root){
        tree.deleteTree(tree.root);
        tree.root = nullptr;
        tree.clearVector();
    }

    if(tree.ReadFileInput("BinaryTreeFiles/", file)){
        tree.Insertion(tree.root, 1);
        tree.Display(tree.root, 0, ' ');
    }
}


void ProgramManager::CheckAVL(BinaryTree& tree)
{
    if(tree.isBalanced(tree.root)){
        std::cout << "Avl: yes" << std::endl;
    }
    else{
        std::cout << "Avl: no" << std::endl;
    }
}

void ProgramManager::Search(std::string file1, std::string file2)
{
    std::cout << "Main Tree" << std::endl;
    BinaryTree tree1;
    if(!tree1.ReadFileInput("BinaryTreeFiles/", file1))
        return;
    tree1.Insertion(tree1.root, 1);
    tree1.Display(tree1.root, 0, ' ');

    std::cout << "\n\nSubtree" << std::endl;
    BinaryTree tree2;
    if(!tree2.ReadFileInput("BinaryTreeSearchFiles/", file2))
        return;
    tree2.Insertion(tree2.root, 1);
    tree2.Display(tree2.root, 0, ' ');

    if(tree1.isSubtree(tree1.root, tree2.root)){
        std::cout << "\nSubtree found" << std::endl;
    }
    else{
        std::cout << "\nSubtree not found!" << std::endl;
    }
}

void ProgramManager::Stats(BinaryTree& tree)
{
    CheckAVL(tree);

    std::vector<int> stats;
    stats.push_back(std::numeric_limits<int>::max());
    stats.push_back(std::numeric_limits<int>::min());
    stats.push_back(0);
    stats.push_back(0);
    tree.Statistics(tree.root, 0, stats);
}

void ProgramManager::Display(BinaryTree& tree)
{
        tree.Display(tree.root, 0, ' ');
}
