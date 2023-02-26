#include<iostream>
#include<functional>
using namespace std;

int add(int x, int y){ return x + y; }

int main(){
    auto p = std::bind(add, 10, 20);
    cout << "add using p as bind = " << p() << endl;
}