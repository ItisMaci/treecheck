#include "BinaryTree.h"

BinaryTree::BinaryTree() : root(nullptr)
{

}

bool BinaryTree::ReadFileInput(std::string folder, std::string file)
{
    std::string fileName = folder + file;

    // Second, check if file opens
    std::ifstream inf(fileName);
    if(!inf.is_open()){
        std::cerr << "Could not open file." << std::endl;
        return false;
    }

    // Third, read file
    int input;
    while (inf >> input) {  // Read input
        if (checkInput(input))  // Push back input if input is new
            numbersToInsert.push_back(input); 
    }
    
    inf.close(); // Close file
    return true;
}

bool BinaryTree::checkInput(int input){
    // Check inf input already exists in our vector numbersToInsert
    for(int intV : numbersToInsert){
        if(intV == input) return false;
    }

    return true;
}

void BinaryTree::Insertion(Node*& node, int i){
    if(!root && !numbersToInsert.empty()){ // If the root is null --> set it
        root = new Node(numbersToInsert.at(0));
        node = root;
    }


    if(numbersToInsert.size() > i){ // Iterates through numbersToInsert and inserts them into the tree
        if(node->data > numbersToInsert.at(i)){                     // If number is smaller than root, insert left
            if(!node->left){                                      // Starting left tree --> if empty, insert with new Node and go to next value in numbers to insert
                node->left = new Node(numbersToInsert.at(i));
                i++;
                Insertion(root, i);
            }
            else{                                                   // If left node is already set, go to this node and and check again
                Insertion(node->left, i);
            }
        }
        else{
            if(!node->right){                                       // Right tree, same as left tree but value is higher than root
                node->right = new Node(numbersToInsert.at(i));
                i++;
                Insertion(root, i);
            }
            else{
                Insertion(node->right, i);
            }
        }
    }
}

int BinaryTree::height(Node* node) {
    if (!node) return 0;
    return 1 + std::max(height(node->left), height(node->right));   // Gets the max() height of the left or right subtree
}

bool BinaryTree::isBalanced(Node* node) {
    if (!node) return true; // return if end of tree

    int lHeight = height(node->left);       // get left subtree height
    int rHeight = height(node->right);      // get right subtree height
    int heightDifference = abs(lHeight - rHeight);  // get absolute height difference

    bool rightBalanced = isBalanced(node->right);   // check if right subtree is balanced
    std::cout << "(" << node->data << ") = " << heightDifference;   // print node data
    if(heightDifference > 1) std::cout << " (AVL violation!)";      // print if violation
    std::cout << std::endl;
    bool leftBalanced = isBalanced(node->left);     // check if left subtree is balanced

    if(heightDifference > 1) {  // if diff is more than 1 (abs(-1) = 1) return false
        return false;
    }

    return leftBalanced && rightBalanced;   // return true if right and left subtree is balanced
}

std::vector<int> BinaryTree::Statistics(Node* node, int depth, std::vector<int>& stats)
{
    if (!node) return stats;    // stats are: min - max - sum - amount of elements

    Statistics(node->right, depth+1, stats); // get stats of right sub tree
    Statistics(node->left, depth+1, stats); // get stats of left sub tree

    if(stats.at(0) > node->data) stats.at(0) = node->data; // get new min
    if(stats.at(1) < node->data) stats.at(1) = node->data;  // get new max
    stats.at(2) += node->data;  // add sum
    stats.at(3)++;              // add +1 to amount

    if(depth == 0){ // print stats when back at root of tree
        double avg = stats.at(2)*1.0f/stats.at(3); //*1.0f because of double
        std::cout << "Min: " << stats.at(0) << " Max: " << stats.at(1) << " Avg: " <<  std::fixed << std::setprecision(2) << avg << std::endl;
    }

    return stats;
}    

bool BinaryTree::areIdentical(Node* rootMain, Node* rootSearch)
{
    if(rootSearch == nullptr && rootMain == nullptr) // if both are null they are the identical
        return true;

    if (rootMain->data == rootSearch->data) {       // if both have the same data they are identical
        return true;
    }

    return false;                                   // every other state returns false
}


bool BinaryTree::isSubtree(Node* rootMain, Node* rootSearch)
{
    if (rootSearch == nullptr) {    // if subtree is null => return true, because it can end before main root
        return true;
    }

    if (rootMain == nullptr) {  // But if main root ends before rootSearch, the subtree is not included => return false
        return false;
    }

    if (areIdentical(rootMain, rootSearch)) {   // check if identical, if identical move one to right and left subtree
        return (isSubtree(rootMain, rootSearch->right)      // only return true if both subtrees are true
                && isSubtree(rootMain, rootSearch->left));
    }

    return isSubtree(rootMain->left, rootSearch) || isSubtree(rootMain->right, rootSearch); // if the current to be searched node is not equal to main node, JUST move to the right and left subtree of Main
}

void BinaryTree::Display(Node* node, int depth, char symbol) { // depth is for adding correct spacing
    if (!node) return;

    Display(node->right, depth + 1, '/');       // print right subtree first to print it correctly in console

    std::cout << std::string(depth * 4, ' ') << symbol << " " << node->data << std::endl;

    Display(node->left, depth + 1, '\\');       // print left subtree
}

void BinaryTree::clearVector()
{
    this->numbersToInsert.clear();
}

void BinaryTree::deleteTree(Node* node) // deletes tree nodes recursively
{
    if(node == nullptr)
        return;

    deleteTree(node->right);
    deleteTree(node->left);

    delete node;
}

BinaryTree::~BinaryTree()
{
    deleteTree(root);
}