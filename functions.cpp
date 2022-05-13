//
// Created by Damien on 13/05/2022.
//
#include <vector>
#include <sstream>
#include "string"
#include "functions.h"

using namespace std;

void get_letter_frequencies(string &content, vector<string> &characters, vector<int> &frequencies){
    for(char const &c : content){
        string s;
        stringstream ss;
        ss << c;
        s = ss.str();
        bool found = false;
        for(int i = 0; i < characters.size(); i++){

            if(characters[i] == s){
                frequencies[i] ++;
                found = true;
                break;
            }
        }
        if(!found){
            characters.push_back(s);
            frequencies.push_back(1);
        }
    }

    for (int i = 0; i < characters.size(); ++i) {
        if(characters[i] == "\n"){
            characters[i] = "\\n";
        }
    }

    sort_by_frequency(characters, frequencies);
    sort_by_aplha(characters, frequencies);
}

void sort_by_frequency(vector<string> &characters, vector<int> &frequencies){
    bool changes = true;
    while (changes){
        changes = false;
        for(int i = 0; i < characters.size()-1; i++){
            if (frequencies[i] > frequencies[i+1]){
                string bucket_character = characters[i];
                int bucket_freq = frequencies[i];

                characters[i] = characters[i+1];
                characters[i+1] = bucket_character;

                frequencies[i] = frequencies[i+1];
                frequencies[i+1] = bucket_freq;
                changes = true;
            }
        }
    }
}

void sort_by_aplha(vector<string> &characters, vector<int> &frequencies){
    bool changes = true;
    while (changes){
        changes = false;
        for(int i = 0; i < characters.size()-1; i++){
            if (characters[i] > characters[i+1] && frequencies[i] == frequencies[i+1]){
                string bucket_character = characters[i];
                int bucket_freq = frequencies[i];

                characters[i] = characters[i+1];
                characters[i+1] = bucket_character;

                frequencies[i] = frequencies[i+1];
                frequencies[i+1] = bucket_freq;
                changes = true;
            }
        }
    }
}