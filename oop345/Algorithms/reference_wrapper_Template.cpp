#include<iostream>
#include<vector>
#include<functional>

int main(){
    std::vector<int> original(5, 10);

    for(auto e:original)
        std::cout << e << " ";
    std::cout << std::endl;    

    std::cout << "original.begin():- "<< *(original.end())<<std::endl;
}