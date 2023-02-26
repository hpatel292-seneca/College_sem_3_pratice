#include<iostream>
#include<numeric>

using namespace std;

int main(){
    int a[] = {3,2,4,1}, s;

    // s = accumulate(a, &a[4], (int)10);

    // cout << "sum = " << s << endl;

    s = accumulate( a, &a[4], int(10), [](int x, int y) {
        cout << "Calling from lymbda. x = " << x << " . y = " << y << endl;
        return x+2*y;
    });
    cout << "sum = " << s << endl;
}