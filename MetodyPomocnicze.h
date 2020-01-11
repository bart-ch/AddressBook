#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze
{
public:
    static string IntToStringConversion(int number);
    static string replaceFirstLetterUppercaseAndOtherLowercase(string text);
    static int StringToIntConversion(string number);
    static string getNumber(string text, int characterPosition);
    static char getCharacter();
    static string getSingleLine();
    static int getInteger();
};

#endif
