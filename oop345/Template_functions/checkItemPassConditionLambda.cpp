// Create a family of functions (a template function) that counts how many elements in an array match a certain condition. The array and the condition are received as parameters. The condition is a lambda expression.


// There are three ways to pass a function as a parameter:

// 1) Function Pointer
// 2) Declare by std::function
// 3) Function template
#include<iostream>
#include<string>

using namespace std;

template<typename T>
int check(T arr[], int size, bool (*func)(T, T)){
    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (func(arr[i], 3))
        {
            count++;
        }
    }
    return count;
}

int main(){
    auto lambFunc = [](int a, int b)->bool {return a > b;};
    int a[] = {1,2,3,4,5,6,7,8,9,0};
    // has to mention template type as lambda exp did not know the template type.
    cout << check<int>(a, 10, lambFunc);
}
