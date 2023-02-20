// Create a family of functions (a template function) that replaces all elements from an array that have a specific value with another specific value. The value to replace and the new value are received as parameters. Specialize for char* to compare the strings by content; if the new value requires more characters than the old value, raise an exception to inform the client.

#include <iostream>
#include <string>
#include<string.h>
using namespace std;
template <typename T>
void changeItemsInArray(T arr[], int size, T old, T new_item)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == old)
        {
            arr[i] = new_item;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

template <>
void changeItemsInArray<char *>(char *arr[], int size, char *old, char *new_item)
{

    if (strlen(new_item) > strlen(old))
    {
        throw "New item has more char* than old char*";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            if (strcmp(arr[i], old) == 0)
            {
                arr[i] = new_item;
            }
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
}
int main()
{
    char* arr[] = {(char*)"Hello", (char*)"bye", (char*)"Hello", (char*)"Harshil"};
    char* old = (char*)"Hello";
    char* new_item = (char*)"HHH";
    changeItemsInArray(arr, 4, old, new_item);
}