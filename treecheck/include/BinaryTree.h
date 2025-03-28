#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Node.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

class BinaryTree{
    private:
        std::vector<int> numbersToInsert{};

    public:
        Node* root;
        BinaryTree();

        // Insert
        bool ReadFileInput(std::string folder, std::string file);
        bool checkInput(int input);
        void Insertion(Node*& node, int i);

        // Balancing
        int height(Node* node);
        bool isBalanced(Node* node);

        // Statistics
        std::vector<int> Statistics(Node* node, int depth, std::vector<int>& stats);

        // Find subtree
        bool areIdentical(Node* rootMain, Node* rootSearch);
        bool isSubtree(Node* rootMain, Node* rootSearch);

        // Display
        void Display(Node* node, int depth, char symbol);

        // Destructor
        void clearVector();
        void deleteTree(Node* node);
        virtual ~BinaryTree();
};

#endif