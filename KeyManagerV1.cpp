// File Name: KeyManagerV1.cpp
//  
// Author: Robert James Castleberry
// Date: 7/28/2016
// Assignment Number: 4
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* KeyManagerV1 class implementation*/
#include <iostream>
#include <cctype>
#include "KeyManagerV1.h"
using namespace std;

// Definition of validateKey member function. This function checks for an 
// existing GOOD key before allowing the user to progress further. If no
// GOOD key is found, the function prompts for input, verifies it, and writes
// it to a file.
bool KeyManagerV1::validateKey()
{
    bool valid;
    ioFile.open("key.txt", ios::in);
    
    // Check for existing key or ask for a new one
    if (ioFile.fail())
    {
        valid = false;
    }
    else if (ioFile)
    {
        // File exists, read and verify key
        ioFile >> currentKey;
        ioFile.clear();
        ioFile.close();

        if (!verifyKey())
        {
            valid = false;
        }
        else if (verifyKey())
        {
            valid = true;
        }
        else
        {
            // Something is wrong!
            cout << "ERROR(2)!\n";
            valid = false;
        }
    }
    else
    {
        // Something is wrong!
        cout << "ERROR(1)!\n";
        valid = false;
    }
    return valid;
}


// Definition of verifyKey member function. This function verifies 
// user input keys
bool KeyManagerV1::verifyKey()
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


// Definition of changeKey member function. This function changes keys if 
// the user input can be verified.
void KeyManagerV1::changeKey()
{
    // Valid key exists, set a new key
    if (validateKey())
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

        // Verify the user input is key
        if (!verifyKey()) 
        {
            // Key is bad. Clear bad key and read old verfied key back into currentKey
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
            // Key is good. Write new verified key to file
            ioFile.open("key.txt", ios::out);
            ioFile << currentKey;
            ioFile.close();
            // Indicate key was changed
            cout << "\nGOOD KEY\n";
            cout << "The key has been changed.\n";
        }
    }
    
    // Valid key does not exist, set a new user input key via a looping prompt
    // to ensure a valid key is obtained before proceeding to the main menu
    else 
    {
        cout << "Please enter a key meeting the following requirements:\n";
        cout << "- At least 8 characters long\n";
        cout << "- Contains at least one uppercase letter\n";
        cout << "- Contains at least one digit\n";
        cout << "- Contains at least one of these four characters: !@#$\n";
        cin.sync();
        getline(cin, currentKey);

        // Loop until the key is verified
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
        cout << "\nGOOD KEY IS NOW IN USE\n";
    }
}

// Definition of the menu member function. This function brings up the main menu for 
// the program.  
void KeyManagerV1::menu()
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
                case 'B': changeKey();
                          break;
                case 'c':
                case 'C': if (validateKey())
                          {
                              cout << "\nGOOD KEY EXISTS AND IS IN USE\n";
                          }
                          else
                          {
                              cout << "\nNO VALID KEY EXISTS\n";
                              changeKey();
                          }
                          break;
                default: cout << "\nThat is an invalid choice\n";
            }
        }
    } while ((choice != 'd') && (choice != 'D'));
}

// Definition of the encryptString member function. This function encrypts
// a user input string using the current key. This function can also decrypt
// a string previously encrypted with the same key.
void KeyManagerV1::encryptString()
{
    // Valid key exists, proceed to encryption menu
    if (validateKey())
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
    // No valid key exists, set a valid key before proceeding
    else
    {
        cout << "\nNO VALID KEY EXISTS\n";
        changeKey();
    }
}
