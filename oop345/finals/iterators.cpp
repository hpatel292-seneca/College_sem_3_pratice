// The vector class template defines classes that manage data structures that can change in size but have their elements ordered in sequence. These classes use contiguous storage locations for their elements and are nearly as efficient as arrays. They store their elements on free store and can adjust their size as required. The class template is optimized for fast random access as well as addition and deletion of elements at the back-end of a sequence.

// #include<vector>
// #include<iostream>

// using namespace std;

// int main(){
//     vector<int> v;

//     if(v.empty()){
//         cout << "The Vector is empty" << endl;
//     }
//     v.push_back(19);
//     v.push_back(45);
//     v.push_back(29);
//     v.push_back(13);
//     v.push_back(15);

//     for (size_t i = 0; i < v.size(); i++)
//     {
//         cout << i << ") " << v[i] << endl;
//     }
//     v.clear();

//     if(v.empty()){
//         cout << "The Vector is empty" << endl;
//     }
    
// }

// The deque class template defines classes that manage doubly-ended queues that can change in size from either end and have elements ordered in sequence. Insertion and deletion of elements at either end is efficient, but elements can be scattered throughout memory in different chunks of storage and contiguous storage is not guaranteed.

// An iterator is an object that points to an element in a sequence. STL iterators simulate sequential access to elements of STL containers, similar to the access that raw pointers provide for elements of simple arrays. Container classes that do not implement contiguous storage of elements require iterators to access their elements. We use iterators to insert elements into a sequence or to remove them from a sequence.

// bind(Fn&& fn, Args&&... args) - binds one or more arguments to a function object

#include<iostream>
#include<functional>
using namespace std;

void task(int i, int j){
    cout << "Int i=" << i << " J=" << j << endl;
}
int main(){
    auto func = bind(task, 10, std::placeholders::_2);

    func(12, 20);
}