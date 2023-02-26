#include<iostream>
#include<functional>

using namespace std;

int main(){
    int i1 = 1, i2 = 2, i3 = 3;

    reference_wrapper<int> r1 = i1;
    reference_wrapper<int> r2 = i2;
    reference_wrapper<int> r3 = i3;

    i1 = 10, i2 = 20, i3 = 30;

    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "r3 = " << r3 << endl;

}