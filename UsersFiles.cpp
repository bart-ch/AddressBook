#include "UsersFiles.h"


UsersFiles::UsersFiles(string fileName)
    :  TextFile(fileName)
{
}

void UsersFiles::addUserToFile(User user)
{
    fstream textFile;
    string lineWithUserData = "";
    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good() == true)
    {
        lineWithUserData = convertUserDataToLineWithDataSeparatedByPipe(user);

        if (isFileEmpty() == true)
        {
            textFile << lineWithUserData;
        }
        else
        {
            textFile << endl << lineWithUserData;
        }
    }
    else
        cout << "Failed to open " << getFileName() << " and save the data." << endl;
    textFile.close();
}

string UsersFiles::convertUserDataToLineWithDataSeparatedByPipe(User user)
{
    string lineWithUserData = "";

    lineWithUserData += AncillaryMethods::IntToStringConversion(user.getId())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}

vector <User> UsersFiles::loadUsersFromFile()
{
    User user;
    fstream textFile;
    vector <User> users;

    string userDataSeparatedByPipe = "";

    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, userDataSeparatedByPipe))
        {
            user = getUserData(userDataSeparatedByPipe);
            users.push_back(user);
        }
    }
    textFile.close();

    return users;
}

User UsersFiles::getUserData(string userDataSeparatedByPipe)
{
    User user;
    string separatedUserData = "";
    int numberOfSeparatedUserData = 1;

    for (int signPosition = 0; signPosition < userDataSeparatedByPipe.length(); signPosition++)
    {
        if (userDataSeparatedByPipe[signPosition] != '|')
        {
            separatedUserData += userDataSeparatedByPipe[signPosition];
        }
        else
        {
            switch(numberOfSeparatedUserData)
            {
            case 1:
                user.setId(atoi(separatedUserData.c_str()));
                break;
            case 2:
                user.setLogin(separatedUserData);
                break;
            case 3:
                user.setPassword(separatedUserData);
                break;
            }
            separatedUserData = "";
            numberOfSeparatedUserData++;
        }
    }
    return user;
}

vector <User> UsersFiles::changePasswordOfLoggedInUser(int loggedInUserId,vector <User> users)
{
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AncillaryMethods::getSingleLine();

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getId() == loggedInUserId)
        {
            users[i].setPassword(newPassword);
            cout << "The password has been changed." << endl << endl;
            system("pause");
        }
    }
    saveAllUsersToFile(users);

    return users;
}

void UsersFiles::saveAllUsersToFile(vector <User> users)
{
    fstream textFile;
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(getFileName().c_str(), ios::out);

    if (textFile.good() == true)
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            lineWithUserData = convertUserDataToLineWithDataSeparatedByPipe(*itr);

            if (itr == itrEnd)
            {
                textFile << lineWithUserData;
            }
            else
            {
                textFile << lineWithUserData << endl;
            }
            lineWithUserData = "";
        }
    }
    else
    {
        cout << "Failed to open a file." << getFileName() << endl;
    }
    textFile.close();
}
