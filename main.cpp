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
    string filePath = "bonjour.txt";
    //string filePath = "C:\\Users\\Damien\\CLionProjects\\HuffmanCompression-CPP\\bonjour.txt";
    cin >> filePath;
    char absolutePathChars[PATH_MAX];
    getcwd(absolutePathChars, PATH_MAX);
    cout << "Treating file :  " << filePath << endl;

    //string absolutePath(absolutePathChars);
    //cout << absolutePath << endl;

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

    return 0;
}
