// Create a family of functions (a template function) that checks if an certain value exists in an array. Both the value and the array are parameters. Specialize for char* to compare the strings by content, not by address.


#include<iostream>
#include<string>
using namespace std;

template<typename T>
bool checkItemExistInArray(T arr[], int size, T item){
    bool retValue = false;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == item)
        {
            retValue = true;
        }
        
    }
    return retValue;
}

int main(){

}