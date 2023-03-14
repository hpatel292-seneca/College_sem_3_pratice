#include<iostream>
#include<typeinfo>
using namespace std;

int main(){
    double a = 20.0;
    long long int b = 20.0;
    auto c = a+b;
    cout << typeid(c).name();
}