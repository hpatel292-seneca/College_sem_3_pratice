// Create a family of functions (a template function) that checks how many times a certain item appears in an array. The function should return the number of occurrences. Specialize for std::string to check how many times the first letter of a string appears in all strings from in the array.

#include<iostream>
#include<string>
using namespace std;
template<typename T>
int checkItemInArray(T arr[], int size, T item){
    int count = 0;
    for(int i = 0; i < size; i++){
        if (arr[i] == item)
        {
            count++;
        }
    }
    return count;
}

template <>
int checkItemInArray<string>(string arr[], int size, string item){
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < arr[i].length(); j++)
        {
            if (arr[i][j] == item[0])
            {
                count++;
            }
            
        }
        
    }
    return count;
}
int main(){
    string arr[] = {string("Hello how are you"), string("what are you doing man"), string("have a good day")};
    int a = checkItemInArray(arr, 3, string("Hello"));
    cout << a;
    return 0;
}