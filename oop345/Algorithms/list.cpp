#include<iostream>
#include<list>
#include"TimedTask.h"

using namespace std;

int main(){
    sdds::TimedTask t; // for checking performance as first define empty deque;
    t.startClock();
    list<double> prices; // initially empty

    if (prices.empty()) // check if prices is empty?
        cout << "Prices is empty!" << endl;

    prices.push_back(10.50);  // add 10.50 at end   
    prices.push_back(45.67);  // add 45.67 at end  
    prices.push_back(67.23);  // add 67.23 at end 
    // adding elements in front
    prices.push_front(-1);    
    prices.push_front(-2);   
    prices.push_front(-3);  
    t.stopClock();
    t.addTask("list initialization empty");
    for(auto e: prices) 
        cout << e <<" ";
    cout << endl;    

    // prices.front() = 22.22; // change 1st element
    // prices[1] = 33.33; // change 2nd element
    // // prices.at(3) = 44.44; // throw an exception as it is out of range
    // prices[2] = 44.44; // change 3rd element
    // cout << "Making changes to all elements of prices" << endl;

    // for(auto e: prices) 
    //     cout << e <<" ";
    // cout << endl;     
    t.startClock();
    list<double> prices1(6); // initially with required space probably didnt need to resize;

    if (prices1.empty()) // check if prices is empty?
        cout << "Prices is empty!" << endl;

    prices1.push_back(10.50);  // add 10.50 at end   
    prices1.push_back(45.67);  // add 45.67 at end  
    prices1.push_back(67.23);  // add 67.23 at end 
    // adding elements in front
    prices1.push_front(-1);    
    prices1.push_front(-2);   
    prices1.push_front(-3);  
    t.stopClock();
    t.addTask("list initialize with required space");
    for(auto e: prices) 
        cout << e <<" ";
    cout << endl;

    cout << "Timing" << endl;
    cout << t;
}
