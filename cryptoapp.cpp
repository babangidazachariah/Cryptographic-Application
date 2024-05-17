/*
*   Copyright: 2023
*   Authors: Q. Mahmoud, Phd and B. Zachariah
*   An Application to encrypt and decrypt content of a file(txt).
*   Input: inputFileName.txt
*   Process: Caesar Encryption/Deceryption Algorithm
*   Output: outputFileName.txt
*   
*
*   To compile: g++ crypto.h crypto.cpp cryptoapp.cpp -o cryptoapp
*/
#include "crypto.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::stringstream;


void printMenu();  // prints menu when program starts

int processAction(string fileName, string ofileName, int userInput);
int main() {
    /*
     implement your solution...use the functions 
     from the crypto.h header file
    */
    int userInput = 0;
    string ifileName, ofileName;
    while (userInput != 3) {
        printMenu();
        cin >> userInput;  // Accept user choice of menu option
        if (userInput == 1) {
            // Accept input file name from user
            cout << "You chose 1. Encryption\n" << endl;
        } else if (userInput == 2) {
            // Accept input file name from user
            cout << "You chose 2. Decryption \n" << endl;
        } else {
            return(3);  // Exit is the chosen option
        }
        cout << "Enter Source/Input File Name: " << endl;
        cin >> ifileName;

        cout <<endl;
        cout << "Enter Destination/Output File Name: " << endl;
        cin >> ofileName;

        if ((ifileName.find(".txt") != string::npos) \
        && (ofileName.find(".txt") != string::npos)) {
            // Create output file
            // ofstream outputFile (ofileName);
            processAction(ifileName, ofileName, userInput);
        } else {
            cout << "Input and Output file types MUST be .txt" << endl;
        }
    }
    cout << "Thank you for using My Cryptographic ";
    cout << "Techniques App. Good Bye!!!" << endl;
    return (0);
}

int processAction(string ifileName, string ofileName, int userInput) {
    vector<int> fileStats;
    ifstream inputCopy;
    // Validate user menu choice
    if (userInput == 1 || userInput == 2 || userInput == 3) {
        // Determine particular user choice for appropriate action
        if (userInput != 3) {
            // Meaning user chose either encryption or decryption
            string line, eword, outFile = "";
            // Create an input stream object that opens a file named "input.txt"
            ifstream input(ifileName);
            ifstream statInput(ifileName);
            /*
            if (userInput == 1) {
                outFile = "encryptedOutput.txt";
            } else {
                outFile = "decryptedOutput.txt";
            }
            */
            // Create an ofstream object and open a file named "output.txt"
            ofstream output(ofileName);
            if (input.is_open() && output.is_open() && statInput.is_open()) {
                fileStats = stats(statInput);
                // Use a loop to read each line from the file
                while (getline(input, line)) {
                    for (unsigned int i = 0; i < line.length(); i++) {
                        // Encrypt characterss
                        if (userInput == 1) {
                            eword += encrypt(line[i]);
                        } else {\
                            eword += decrypt(line[i]);
                        }
                       // Write encrypted word to output file
                        output << eword;
                        eword = "";
                    }
                    output << "\n";
                }
                // print file statistics
                cout << "\n";
                cout << "The program has processed ";
                cout << ifileName << ":" << endl;
                cout << fileStats.at(2) << " characters" << endl;
                cout << fileStats.at(1) << " words" << endl;
                cout << fileStats.at(0) << " lines" << endl;
                cout << "\n\n";
            } else {
                cout << "There was problem processing your file. ";
                cout << "Try Again!!!" << endl;
                return (2);  // There was problem
            }
        }
    } else {
        cout << "Invalid Option Selection. Restart Again!!!" <<endl;
        return (4);  // Invalid option selection.
    }
    return (1);  // action completed succesfully.
}
void printMenu() {
    cout << "Welcome to My Cryptographic Techniques \n" << endl;
    cout << "Please enter your selection:" <<endl;
    cout << endl;
    cout << "1. Encrypt" <<endl;
    cout << "2. Decrypt" <<endl;
    cout << "3. Exit" <<endl;
}
