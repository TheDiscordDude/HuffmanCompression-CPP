//
// Created by Damien on 13/05/2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include "functions.h"
#include "Tree.h"

using namespace std;


int main(int argc, char *argz[])
{

    cout << "Which file do you wish to compress ?" << endl;
    string filePath;
    cin >> filePath;
    char absolutePathChars[PATH_MAX];
    getcwd(absolutePathChars, PATH_MAX);
    cout << "Treating file :  " << filePath << endl;


    string fileContent = "";
    ifstream file(filePath);

    if(file.is_open()){
        string line = "";
        while(getline(file, line)){
            fileContent += line + "\n";
        }
    }
    file.close();

    // now get characters and frequencies

    vector<string> characters;
    vector<int> frequencies;

    get_letter_frequencies(fileContent, characters, frequencies);

    // creating forest

    vector<Tree> forest;
    for(int i = 0; i < characters.size(); i ++){
        forest.push_back(Tree(characters[i], frequencies[i], NULL, NULL));
    }

    // For the love of god I don't know why, but when we do a first operation in the forest using
    // its own elements like so, It ALWAYS fails, but only the FIRST time
    // I don"t why, but the only way to make sure this problem doesn't appear
    // is to trigger the problem, then we don"t have to deal with it ever agin.
    forest.push_back(Tree(string(""), forest[0].get_frequency() + forest[1].get_frequency(), &forest[0], &forest[1]));
    forest.pop_back();

    for(int i = 0; i < forest.size() - 1; i+=2){
        int new_frequency = forest[i].get_frequency() + forest[i + 1].get_frequency();
        Tree fusion_tree = Tree(string(""),new_frequency,&forest[i],&forest[i + 1]);
        bool inserted = false;
        for(int j = 2; j < forest.size() ; j++){
            if (forest[j].get_frequency() == new_frequency && !inserted){
                forest.insert(forest.begin() + j, fusion_tree);
                inserted = true;
            }
        }
        if(!inserted){
            forest.push_back(fusion_tree);
        }
    }

    string result = forest[forest.size()-1].to_string();
    cout << result;

    return 0;
}
