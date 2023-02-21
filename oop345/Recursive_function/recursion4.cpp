// Define a recursive function that receives an integer as a parameter and finds out how many times the number can be divided by 2 (without a reminder).

#include<iostream>
using namespace std;

int count(int num){
    if (num%2!=0 || num <2)
    {
        return 0;
    }
    int a = num%2==0;
    return (a + count(num/2));
}
int main(){
    cout << count(8);
}