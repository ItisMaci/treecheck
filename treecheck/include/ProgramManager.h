#ifndef PROGRAMMANAGER_H
#define PROGRAMMANAGER_H
#include <iostream>
#include <limits>
#include "BinaryTree.h"

class ProgramManager{
    private:

    public:
        ProgramManager();
        void treecheck(std::string file);
        void treecheck(std::string file1, std::string file2);

        // Render
        void ClearScreen();
        void PauseScreen();

        // Binary Tree
        void Import(BinaryTree& tree, std::string file);
        void CheckAVL(BinaryTree& tree);
        void Search(std::string file1, std::string file2);
        void Stats(BinaryTree& tree);
        void Display(BinaryTree& tree);

        
};

#endif