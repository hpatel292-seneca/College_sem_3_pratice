#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    std::vector<int> v = {1,2,4,5,7,8,10,13,17,21,43};
    std::vector<int> c(15);

    copy_if(v.begin(), v.begin()+10, c.begin(), [](int i)->bool{return i%2;});

    for(auto e:c){
        cout << e << std::endl;
    }
}