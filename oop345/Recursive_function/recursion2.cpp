// Define a recursive function that receives an std::string as a parameter and counts how many times the letter a appears.

#include<iostream>
#include<string>
using namespace std;

int countInString(string str){
    if (str.length() == 0)
    {
        return 0;
    }
    else if (str[0] == 'a')
    {
        return 1 + countInString(str.substr(1, str.length()));
    }
    return 0 + countInString(str.substr(1, str.length()));
    
}

int main(){
    cout << countInString(string("hello world aacha kem choa"));
}