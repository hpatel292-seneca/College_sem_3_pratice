// Define a recursive function that receives an array of integers as parameter and returns how many even numbers are in the array.

#include<iostream>
using namespace std;

int countEvenArray(int arr[], int size){
    if (size == 1)
    {
        return arr[0]%2==0?1:0;
    }
    return countEvenArray(arr, size-1)+(arr[size-1])%2==0?1:0;
    
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    cout << countEvenArray(arr, 9);
}