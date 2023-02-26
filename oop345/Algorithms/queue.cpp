#include<iostream>
#include<queue>

using namespace std;

int main(){
    std::queue<double> prices;

    prices.push(10.43);
    prices.push(23.45);
    prices.push(54.32);
    prices.push(14.78);
    prices.push(95.32);
    prices.push(45.54);

    while(!prices.empty()) {
        cout << prices.front() << " ";
        prices.pop();
    }

    cout << endl;
}