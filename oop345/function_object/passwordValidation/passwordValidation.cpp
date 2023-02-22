// Create a functor (a function object) that validates a password. At instantiation, the function object should receive from the client.

#include<iostream>
#include<string>
#include"password.h"
using namespace std;



int main(){
    password pwdChecker;
    cout << pwdChecker(std::string("HARSHIL@"));
    // cout << std::string("Harshil@").find('@');
}