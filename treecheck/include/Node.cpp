#include "Node.h"

Node::Node()
{
    this->right = nullptr;
    this->left = nullptr;
}

Node::Node(int data) : data(data)
{
    this->right = nullptr;
    this->left = nullptr;
}

Node::~Node(){}