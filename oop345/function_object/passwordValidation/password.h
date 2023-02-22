// Create a functor (a function object) that validates a password. At instantiation, the function object should receive from the client

// a set of characters -> the valid password must contain at least one (i.e., special characters like #!@$%^&*());
// a set of characters that should not be in the password (i.e., space, new line, etc)
// Through modifiers, the client should be able to specify if the password must contain at least:

// one lower case letter (by default, yes)
// one upper case letter (by default, yes)
// a number (be default, no)
// a minimum number of characters (by default, no; if yes, then the client must specify this minimum).
// The functor should return true if a password is valid; false otherwise;

#ifndef SDDS_PASSWORD_H
#define SDDS_PASSWORD_H
#include<iostream>
#include<string>

class password{
    bool lowerCase{true};
    bool upperCase{true};
    bool aNumber{true};
    int minChar{-1};
    public:
    bool operator()(std::string password);
};

bool password::operator()(std::string pwd){
    bool retValue = true;
    if (pwd.find('#') == -1 && pwd.find('!') == -1 && pwd.find('@') == -1 && pwd.find('$') == -1 && pwd.find('%') == -1 && pwd.find('^') == -1 && pwd.find('*') == -1 && pwd.find('(') == -1 && pwd.find(')') == -1 )
    {
        retValue = false;
        std::cout << "Didn't have any special char '#!@$%^&*()'" << std::endl;
    }
    if ( !(pwd.find(' ') == -1 && pwd.find('\n') == -1))
    {
        retValue = false;
        std::cout << "has either space or new line" << std::endl;
    }
    
    if (lowerCase && retValue)
    {
        bool present = false;
        for (size_t i = 0; i < pwd.length(); i++)
        {
            if (pwd[i] > 'a' && pwd[i] < 'z')
            {
                present = true;
            }
        }
        retValue = present?true:false;
    }
    if (upperCase && retValue)
    {
        bool present = false;
        for (size_t i = 0; i < pwd.length(); i++)
        {
            if (pwd[i] > 'A' && pwd[i] < 'Z')
            {
                present = true;
            }
        }
        retValue = present?true:false;
    }
    if (aNumber && retValue)
    {
        bool present = false;
        for (size_t i = 0; i < pwd.length(); i++)
        {
            if (pwd[i] > '0' && pwd[i] < '9')
            {
                present = true;
            }
        }
        retValue = present?true:false;
    }
    if (minChar != -1 && retValue)
    {
        retValue = pwd.length()>=minChar?true:false;
    }
    
    return retValue;
}

#endif