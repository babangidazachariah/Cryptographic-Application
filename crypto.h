/*
*   Copyright: 2023
*   Authors: Q. Mahmoud, Phd and B. Zachariah
*   Crypto Application header file: Specify the 
*       cryptographic functions that may be used for 
*       encryption, decryption, and generation file 
*       content statistics.
*/
#ifndef CRYPTO_H
#define CRYPTO_H
#include <iostream>
#include <vector>

#include <fstream>
using std::ifstream;
// given a char c return the encrypted character
char encrypt(char c);
// given a char c retun the decrypted character
char decrypt(char c);
/* given a reference to an open file, return a 
vector with the # of characters, words, lines.
*/
std::vector<int> stats(ifstream& infile);
#endif  // CRYPTO_H
