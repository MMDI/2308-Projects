// File Name: KeyManagerV1.h 
//  
// Author: Robert James Castleberry
// Date: 7/28/2016
// Assignment Number: 4
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* KeyManagerV1 class specification*/
#ifndef KEYMANAGERV1_H
#define KEYMANAGERV1_H
#include <fstream>
#include <string>
using namespace std;

class KeyManagerV1
{
    private:
        fstream ioFile;
        string currentKey;
        string packet;
    public:
        KeyManagerV1() { ; }
        ~KeyManagerV1() { ; }
        bool validateKey();
        bool verifyKey();
        void changeKey();
        void encryptString();
        void menu();
};
#endif
