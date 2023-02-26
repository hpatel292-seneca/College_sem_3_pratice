#include<vector>
#include<iostream>

using namespace std;

int main(){
    vector<int> num;
    vector<int>::iterator it;

    num.push_back(10);
    num.push_back(20);
    num.push_back(30);
    num.push_back(40);
    num.push_back(50);

    for (it = num.begin(); it != num.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
}