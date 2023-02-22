#include<iostream>
#include<string>
#include"spaceRemover.h"

using namespace std;

int main(){
    spaceRemover spaceRemover;
    string str = "   Harshil    ";
    cout << "Original : "<< str << endl;
    cout << "After    : "<<spaceRemover(str) << endl;
}