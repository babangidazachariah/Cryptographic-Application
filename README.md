[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/TX22O3s-)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=12240826&assignment_repo_type=AssignmentRepo)
Please follow the guidelines in the assignment description.
<h1>Cryptographic Application</h1>

An application to Encrypt and Decrypt contents of text files and then generate the statistics of the content of input file in terms of number of **lines, words** and **characters**.

The application demonstrates the use of **header file(s) in c++**

Three functions are declared in the header file, **crypto.h**

The functions include:
**char encrypt(char c)**

**char decrypt(char c)**

**vector<int> stats(ifstream& infile)**

The cryptographic algorithm used was the **Caesar Encryption Algorithm**, which is a simple and ancient method of encrypting text by shifting each letter of the alphabet by a fixed number of positions. For example, if the shift is 3, then A becomes D, B becomes E, C becomes F, and so on [<a href="https://cryptii.com/pipes/caesar-cipher">1</a> <a href="https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/">2</a>]. 

The function used for the encryption is:

**e = (c - 'A' + k) % 26 + 'A'**

The decryption function used is:

**d = (c - 'A' - k + 26) % 26 + 'A';**

Where **e** is the returned encrrypted character, **c** is the charcter to be encrypted, **d** is the returned decrypted character, and **k** is the encryption key.


<h3>Usage:</h3>
To use the application, clone the repository using: 

  <strong><em>
  
      git clone https://github.com/UOITEngineering/programmingassignment2-babangidazachariah.git
      
      cd /programmingassignment2-babangidazachariah 
      
  </em></strong>
  
Compile the application using: 

  <strong><em>
  
      g++ -Wall crypto.h crypto.cpp cryptoapp.cpp -o cryptoapp
      
  </em></strong>
  
Execute the application using:

  <strong><em>
  
      ./cryptoapp
      
  </em></strong>

Once executed, a menu option is displayed as shown in Figure 1

<img src="https://github.com/UOITEngineering/programmingassignment2-babangidazachariah/blob/main/executedMenu.PNG" >
Figure 1: Menu Items Selection


To encrypt the content of a text file, Enter **1** and then Enter the **file name**. 

Note that file names are expected to end with **.txt** extension and the file name should be **without spaces**.

For example, **input.txt** or **inputfile.txt**
see Figure 2.

Also, specify the **output file**, following the same pattern as recommended above. See Figure 2

<img src = "https://github.com/UOITEngineering/programmingassignment2-babangidazachariah/blob/main/figure2.png" >

Figure 2: Menu selection and Input/Output File Name Specification

User inputs are marked with red colors in the Figures.

Once a menu option has been chosen, as well as the source/input and destination/output file names have been correctly specified (as in Figure 2), the program performs the chosen action (encryption or decryption), save the output to the specified file, and then generate the statistics of the input file as shown in Figure 3.

<img src = "https://github.com/UOITEngineering/programmingassignment2-babangidazachariah/blob/main/figure3.png" >

Figure 3: File Statistics

To decrypt the encrypted content of a file, the procedure is followed. However, the source/input file is the file containing the encrypted content (text) while the destintion/output file is the file into which the decrypted content is stored. See Figure 4.

<img src = "https://github.com/UOITEngineering/programmingassignment2-babangidazachariah/blob/main/figure4.png" >

Figure 4: Decryption 

The **sample source/input file (input.txt), encrypted file content (myoutput.txt)** and the **decrypted file (decryptmyoutput.txt)** are as shown in Figure 5

<img src = "https://github.com/UOITEngineering/programmingassignment2-babangidazachariah/blob/main/figure5.png" >

Figure 5: Sample Files
