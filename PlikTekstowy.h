#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy
{
    const string FILE_NAME;

public:

    PlikTekstowy(string fileName)
        : FILE_NAME(fileName)
    {
    }

    string getFileName();
    bool isFileEmpty();
};

#endif
