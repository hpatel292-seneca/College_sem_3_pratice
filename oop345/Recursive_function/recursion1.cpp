// Define a recursive function that receives an integer n as a parameter and calculates the formula (0 × 1) + (1 × 2) + (2 × 3) + (3 × 4) + ... (n-1)×n.
#include<iostream>
using namespace std;

int formula(int n){
    if (n <= 1)
    {
        return n;
    }
    return formula(n-1)*(n+formula(n-2));
}

int main(){
    cout << formula(3);
}