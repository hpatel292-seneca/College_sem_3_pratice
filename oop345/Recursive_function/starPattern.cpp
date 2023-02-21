#include<iostream>
using namespace std;

int starPattern(int n){
    for (size_t i = 0; i < n; i++)
    {
        cout<<"*";
    }
    cout << endl;
    if(n != 1){
    starPattern(n-1);
    }
}

int main(){
    starPattern(5);
}