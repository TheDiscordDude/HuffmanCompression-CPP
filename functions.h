//
// Created by Damien on 13/05/2022.
//

#ifndef HUFFMANCOMPRESSION_CPP_FUNCTIONS_H
#define HUFFMANCOMPRESSION_CPP_FUNCTIONS_H

#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void get_letter_frequencies(string &content, vector<string> &characters, vector<int> &frequencies);
void sort_by_frequency(vector<string> &characters, vector<int> &frequencies);
void sort_by_aplha(vector<string> &characters, vector<int> &frequencies);

#endif //HUFFMANCOMPRESSION_CPP_FUNCTIONS_H
