// Create a family of functions (a template function) that searches in an array an element that matches a certain predicate. The predicate is received as parameter and is a lambda expression. Return the address of the first element that matches, or null if no match is found.

#include<iostream>
#include<string>
using namespace std;

template<typename T>
int predicateAsLambda(T arr[], int size, bool (*func)(T a, T b), T item){
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (func(arr[i], item))
        {
            count++;
        }
        
    }
    return count;
}

int main(){
    auto lambFunc = [](int a, int b)->bool{return a < b;};
    int a[] = {1,2,3,4,5,6,7,8,9,0};
    // passing lambda expression as argument, as in parameter of lambda exp. we define explict type, we need to define explict type in function name as well
    cout << predicateAsLambda<int>(a, 10, lambFunc, 4);

}