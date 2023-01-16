#include<iostream>
#include<cstring>

union product{
    unsigned sku;
    char desc[100];
};

int main(){
    product a1, a2;

    a1.sku = 1234;
    std::strcpy(a2.desc, "It is a new product for health");

    std::cout << a1.sku <<std::endl;
    std::cout << a2.desc <<std::endl;
}