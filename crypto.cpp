/*
*   Copyright: 2023
*   Authors: Q. Mahmoud, Phd and B. Zachariah
*   Crypto Application header functions implementation: 
*       Specify the cryptographic functions that may be  
*       used for encryption, decryption, and generation 
*       file content statistics.
*/
// provide implementation to the functions in crypto.h
// no main() in this file

#include "crypto.h"
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;
int k = 3;
// given a char c return the encrypted character
char encrypt(char c) {
    if (isalpha(c)) {
        char e;
        e = (c - 'A' + k) % 26 + 'A';
        return e;
    } else {
        return (c);
    }
}
// given a char c retun the decrypted character
char decrypt(char c) {
     if (isalpha(c)) {
        char d;
        d = (c - 'A' - k + 26) % 26 + 'A';
        return d;
    } else {
        return (c);
    }
}
/* 
given a reference to an open file, return a 
vector with the # of characters, words, lines 
*/
std::vector<int> stats(ifstream& infile) {
    vector<int> st;
    int c = 0, w = 0, ch = 0, wd = 0, ln = 0;
    string line, word, delimiter = " ";
    bool comp = true;
    size_t pos;
    // cout << "Stats:" << endl;
    // Use a loop to read each line from the file
    while (getline(infile, line)) {
        // cout << "While:" << endl;
        ln++;
        while (comp) {
            w++;

            pos = line.find(delimiter);
            // Check if there is no more delimiter in the line
            if (pos == string::npos) {
                // Print the remaining word in the line
                word = line;
                comp = false;
            } else {
                /* 
                Get the word from the line based on 
                the position of the delimiter 
                */
                word = line.substr(0, pos);
                c += 1;
            }

            c += word.length();

            // cout << c <<endl;
            // Erase the word and the delimiter from the line
            line.erase(0, pos + delimiter.length());
        }
        wd += w;
        ch += c;
    }
    st.push_back(ln);
    st.push_back(wd);
    st.push_back(ch);
    /*
    for(unsigned int i = 0; i < st.size(); i++){
        cout << st.at(i) << endl;
    }
    */
    return st;
}

