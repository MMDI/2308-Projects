// File Name: KeyManager.h 
//  
// Author: Robert James Castleberry
// Date: 7/28/2016
// Assignment Number: 4
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* KeyManager class specification*/
#ifndef KEYMANAGER_H
#define KEYMANAGER_H
#include <fstream>
#include <string>
using namespace std;

class KeyManager
{
    private:
        fstream ioFile;
        string currentKey;
        string packet;
    public:
        KeyManager() { ; }
        ~KeyManager() { ; }
        void ValidateKey();
        bool verifyKey();
        void ChangeKey();
        void encryptString();
        void menu();
};
#endif
