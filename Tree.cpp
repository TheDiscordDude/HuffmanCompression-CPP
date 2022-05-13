//
// Created by Damien on 13/05/2022.
//

#include "Tree.h"

Tree::Tree(const string &label, const int frequency, Tree *left_child, Tree *right_child) : label(label), frequency(frequency), left_child(left_child), right_child(right_child) {}

ostream &operator<<(ostream &strm, const Tree &t) {
    string left_child_string;
    if(t.left_child == NULL){
        left_child_string.assign("null");
    } else {
        cout << to_string(sprintf(NULL, "%s", t.left_child));
        char *left_child_chars = new char[sprintf(NULL, "%s", t.left_child)];
        sprintf(left_child_chars, "%s", t.left_child);
        left_child_string.assign(left_child_chars);
    }

    string right_child_string;
    if(t.right_child == NULL){
        right_child_string.assign("null");

    } else {
        char *right_child_chars = new char[sprintf(NULL, "%s", t.right_child)];
        sprintf(right_child_chars, "%s", t.right_child);
        right_child_string.assign(right_child_chars);
    }

    return strm << string("{\"label\":'") << t.label
                << string("', \"frequency\":") << to_string(t.frequency)
                << string(", \"left_child\":") << left_child_string
                << string(", \"right_child\":") << right_child_string;
}

Tree* Tree::get_left_child() {
    return left_child;
}

Tree* Tree::get_right_child() {
    return right_child;
}

string Tree::to_string() {
    string left_child_string ;

    if(left_child == NULL){
        left_child_string.assign("null");
    } else {
        left_child_string = left_child->to_string();
    }

    string right_child_string;
    if(right_child == NULL){
        right_child_string.assign("null");

    } else {
        right_child_string = right_child->to_string();
    }

    return string("{\"label\":\"") + label
           + string("\", \"frequency\":") + std::to_string(frequency)
           + string(", \"left_child\":") + left_child_string
           + string(", \"right_child\":") + right_child_string
           + string ("}");
}

int Tree::get_frequency() {
    return frequency;
}

string Tree::get_label() {
    return label;
}

Tree::Tree(Tree *pTree) {
    label = pTree->get_label();
    frequency = pTree->get_frequency();
    left_child = pTree->get_left_child();
    right_child = pTree->get_right_child();
}
