// Create a family of functions (a template function) that calculates the sum of all elements from an array received as parameter. Specialize for std::string to concatenate the strings, separated by comma (,).

#include<iostream>
#include<string>
using namespace std;
template<typename T>
T sumItemsOfArray(T arr[], int size){
    T sum{};
    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

template<>
string sumItemsOfArray<string>(string arr[], int size){
    string sum = "";
    for (size_t i = 0; i < size; i++)
    {
        sum += arr[i];
        sum += ",";
    }
    return sum;
}
int main(){
    string arr[] = {string("Hello"), string("How"), string("are"), string("you")};
    cout << sumItemsOfArray(arr, 4);
}