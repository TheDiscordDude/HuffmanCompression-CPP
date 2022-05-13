//
// Created by Damien on 13/05/2022.
//

#ifndef HUFFMANCOMPRESSION_CPP_TREE_H
#define HUFFMANCOMPRESSION_CPP_TREE_H

#include "string"
#include "iostream"
using namespace std;

class Tree {
private:
        string label;
        int frequency;
public:
    Tree(const string &label, const int frequency, Tree *leftChild, Tree *rightChild);
    friend ostream& operator<<(ostream &strm, const Tree &t);
    Tree get_left_child();
    Tree get_right_child();
    string to_string();

private:
    Tree* left_child;
    Tree* right_child;
};


#endif //HUFFMANCOMPRESSION_CPP_TREE_H
