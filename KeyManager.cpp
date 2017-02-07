// File Name: KeyManager.cpp
//  
// Author: Robert James Castleberry
// Date: 7/28/2016
// Assignment Number: 4
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* KeyManager class implementation*/
#include <iostream>
#include <cctype>
#include "KeyManager.h"
using namespace std;

// Definition of ValidateKey member function. This function checks for an 
// existing GOOD key before allowing the user to progress further. If no
// GOOD key is found, the function prompts for input, verifies it, and writes
// it to a file.
void KeyManager::ValidateKey()
{
    ioFile.open("key.txt", ios::in);
    
    // Check for existing key or ask for a new one
    if (ioFile.fail())
    {
        // File does not exist, prompt for new key and verify
        cout << "\nNO KEY EXISTS\n";
        cout << "Please enter a key meeting the following requirements:\n";
        cout << "- At least 8 characters long\n";
        cout << "- Contains at least one uppercase letter\n";
        cout << "- Contains at least one digit\n";
        cout << "- Contains at least one of these four characters: !@#$\n";
        cin.sync();
        getline(cin, currentKey);

        while (!verifyKey()) 
        {
            currentKey.clear();
            cout << "\nBAD KEY\n";
            cout << "Please enter a key meeting the requirements:\n";
            cout << "- At least 8 characters long\n";
            cout << "- Contains at least one uppercase letter\n";
            cout << "- Contains at least one digit\n";
            cout << "- Contains at least one of these four characters: !@#$\n";
            cin.sync();
            getline(cin, currentKey);
        }
        // Write new verified key to file
        ioFile.clear();
        ioFile.open("key.txt", ios::out);
        ioFile << currentKey;
        ioFile.close();
    }
    else if (ioFile)
    {
        // File exists, read and verify key
        ioFile >> currentKey;
        ioFile.clear();
        ioFile.close();

        if (!verifyKey())
        {
            // Loop until user inputs a GOOD key
            while (!verifyKey()) 
            {
                currentKey.clear();
                cout << "\nBAD KEY\n";
                cout << "Please enter a key meeting the requirements:\n";
                cout << "- At least 8 characters long\n";
                cout << "- Contains at least one uppercase letter\n";
                cout << "- Contains at least one digit\n";
                cout << "- Contains at least one of these four characters: !@#$\n";
                cin.sync();
                getline(cin, currentKey);
            }
            // Write GOOD key to a file 
            ioFile.open("key.txt", ios::out);
            ioFile << currentKey;
            ioFile.close();
            cout << "\nGOOD KEY\n";
            cout << "Key has been updated!\n";
        }
        else if (verifyKey())
        {
            // Indicates exisiting key is good and will be used
            cout << "\nGOOD KEY\n";
            cout << "Using the existing good key!\n";
        }
        else
        {
            // Something is wrong!
            cout << "ERROR(2)!\n";
        }
    }
    else
    {
        // Something is wrong!
        cout << "ERROR(1)!\n";
    }
}


// Definition of verifyKey member function. This function verifies 
// user input keys
bool KeyManager::verifyKey()
{
    bool test = true;
    int length = currentKey.length();
    char check;

    // Check length
    if (length < 8)
    { 
        test = false;
        return test;
    }
    
    // Check for at least one uppercase letter
    test = false;
    for (int count = 0; count < length; count++)
    {
        check = currentKey.at(count);
        if (isupper(check))
        {
            test = true;
            break;
        }
    }
    if (!test)
    {
        return test;
    }

    // Check for at least one digit
    test = false;
    for (int count = 0; count < length; count++)
    {
        check = currentKey.at(count);
        if (isdigit(check))
        {
            test = true;
            break;
        }
    }
    if (!test)
    {
        return test;
    }

    // Check for at least one special character from: !@#$
    test = false;
    for (int count = 0; count < length; count++)
    {
        check = currentKey.at(count);
        if ((check == '!') || (check == '@') || (check == '#') || (check == '$'))
        {
            test = true;
            break;
        }
    }

    return test;
}


// Definition of ChangeKey member function. This function changes keys if 
// the user input can be verified.
void KeyManager::ChangeKey()
{
    currentKey.clear();
    cout << "\nNEW KEY\n";
    cout << "Please enter a key meeting the following requirements:\n";
    cout << "- At least 8 characters long\n";
    cout << "- Contains at least one uppercase letter\n";
    cout << "- Contains at least one digit\n";
    cout << "- Contains at least one of these four characters: !@#$\n";
    cin.sync();
    getline(cin, currentKey);

    if (!verifyKey()) 
    {
        // Clear bad key and read old verfied key back into currentKey
        currentKey.clear();
        ioFile.open("keytxt", ios::in);
        ioFile >> currentKey;
        ioFile.clear();
        ioFile.close();
        // Indicate key was not changed
        cout << endl << "\nBAD KEY\n";
        cout << "The key has NOT been changed.\n";
    }
    else
    {
        // Write new verified key to file
        ioFile.open("key.txt", ios::out);
        ioFile << currentKey;
        ioFile.close();
        // Indicate key was changed
        cout << "\nGOOD KEY\n";
        cout << "The key has been changed.\n";
    }
}

// Definition of the menu member function. This function brings up the main menu for 
// KeyManager functionality.
void KeyManager::menu()
{
    char choice;  // To store user input menu choice
    
    do
    {
        cout << "\n\nMAIN MENU\n";
        cout << "Please choose one of the following options:\n";
        cout << "A - Encrypt string\n";
        cout << "B - Change Key\n";
        cout << "C - Validate Key\n";
        cout << "D - Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        // Unless quit is selected, presents menu in a loop and accounts for
        // lower case character input
        if ((choice != 'd') && (choice != 'D'))
        {
            switch (choice)
            {
                case 'a':
                case 'A': encryptString();
                    break;
                case 'b':
                case 'B': ChangeKey();
                    break;
                case 'c':
                case 'C': ValidateKey();
                    break;
                default: cout << "\nThat is an invalid choice\n";
            }
        }
    } while ((choice != 'd') && (choice != 'D'));
}

// Definition of the encryptString member function. This function encrypts
// a user input string using the current key. This function can also decrypt
// a string previously encrypted with the same key.
void KeyManager::encryptString()
{
    char cryptChoice;  // To store choice of encryption or decryption
    bool flag = false;  // To signal invalid input;

    // Ask user what they want to do
    cout << "\nENCRYPTION MENU\n";
    cout << "Please choose an option: \n";
    cout << "A - Encrypt a string\n";
    cout << "B - Decrypt existing string\n";
    cout << "Enter your choice: ";
    cin >> cryptChoice;
    cin.ignore();
 
    switch (cryptChoice)
    {
        case 'a':
        case 'A': cout << "\nPlease enter the string you want to encrypt: \n";
                  packet.clear();
                  cin.sync();
                  getline(cin, packet);
                  break;
        case 'b':
        case 'B':
                  break;
        default: cout << "\nInvalid choice. Exiting to main menu.\n";
                 flag = true;
    }
    
    // Check for invalid choice and proceed
    if (!flag)
    {
        // Encrypt or decrypt the string
        int m = packet.length();
        int n = currentKey.length();
        
        for (int k = 0; k < m; k++)
        {
            packet[k] ^= currentKey[k % n];
        }
        // Change unprintable characters to spaces
        string toPrint(packet);
        for (int j = 0; j < m; j++)
        {
            if (!isprint(toPrint[j]))
            {
                toPrint[j] = ' ';
            }
        }
        // Print the new string
        cout << "\nNow your string says: \n" << toPrint;
    }
}
