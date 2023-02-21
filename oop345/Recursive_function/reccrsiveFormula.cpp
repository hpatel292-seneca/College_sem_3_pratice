// Define a recursive function that receives an integer n as a parameter and calculates the formula: 1 + 2×2 + 3 + 2×4 + 5 + 2×6 + ... up to n.'

#include<iostream>
using namespace std;

int formula(int n){
    if (n == 1)
    {
        return n;
    }
    else if (n%2 == 0)
        return 2*n + formula(n-1);
    return n + formula(n-1);    
}

int main(){
    cout << formula(5);
}