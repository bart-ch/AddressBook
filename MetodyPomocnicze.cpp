#include "MetodyPomocnicze.h"

string MetodyPomocnicze::IntToStringConversion(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze::replaceFirstLetterUppercaseAndOtherLowercase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int MetodyPomocnicze::StringToIntConversion(string number)
{
    int liczbaInt;
    istringstream iss(number);
    iss >> liczbaInt;

    return liczbaInt;
}

string MetodyPomocnicze::getNumber(string text, int characterPosition)
{
    string liczba = "";
    while(isdigit(text[characterPosition]) == true)
    {
        liczba += text[characterPosition];
        characterPosition ++;
    }
    return liczba;
}

char MetodyPomocnicze::getCharacter()
{
    string input = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "Must be a single character. Please reenter." << endl;
    }
    return sign;
}

string MetodyPomocnicze::getSingleLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

int MetodyPomocnicze::getInteger()
{
    string input = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}
