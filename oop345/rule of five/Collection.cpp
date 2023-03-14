#include<iostream>
#include"Collection.h"
using namespace std;
int main(){
    sdds::Collection<int> c;
    
    int i = 10;
    c.add(i);
    c.add(i);
    c.add(i);
    c.display();
}