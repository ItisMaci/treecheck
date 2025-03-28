#ifndef NODE_H
#define NODE_H

class Node{
    private:

    public:
        int data;
        Node* right;
        Node* left;

        Node();
        Node(int data);
        virtual ~Node();
};

#endif