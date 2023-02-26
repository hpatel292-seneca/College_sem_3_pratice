#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<double> prices; // initially empty

    if (prices.empty()) // check if prices is empty?
        cout << "Prices is empty!" << endl;

    prices.push_back(10.50);  // add 10.50   
    prices.push_back(45.67);  // add 45.67  
    prices.push_back(67.23);  // add 67.23 

    for(auto e: prices) 
        cout << e <<" ";
    cout << endl;    

    prices.front() = 22.22; // change 1st element
    prices[1] = 33.33; // change 2nd element
    // prices.at(3) = 44.44; // throw an exception as it is out of range
    prices[2] = 44.44; // change 3rd element
    cout << "Making changes to all elements of prices" << endl;

    for(auto e: prices) 
        cout << e <<" ";
    cout << endl;     
             
}