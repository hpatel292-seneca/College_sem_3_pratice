// writing code for sorting an array of any type
#include<iostream>
using namespace std;
template<typename T>
bool ascending(T& a, T& b){return a > b;}

template<typename T>
bool descending(T& a, T& b){return a < b;};

template<typename T, typename func>
void sort(T a[], int n, func comp){
    for (int i = n - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (comp(a[j], a[j+1]))
            {
                T temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
}

template <typename T>
void display(T* a, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}

int main(){
    auto ab = [](int& a, int& b)->bool{return a<b;};
    int arr[] = {1,2,3,4,5,6,7};
    cout << "Arrays: ";
    display(arr, 7);
    cout << endl;

    sort(arr, 7, ab);
    cout << "Arrays: ";
    display(arr, 7);
    cout << endl;


}