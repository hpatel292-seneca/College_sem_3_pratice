// // String Literals: A string literal is an unmodifiable lvalue. We may not change its contents.
// // Pointing to a String Literal
// // ptrToStringLiteral.cpp

// // #include <iostream>

// // int main()
// // {
// //     const char *p  = "Avoid overwriting"; // poor coding style; newer compilers might flag this line

// //     p[0] = 'a';  // ISO C++ forbids converting a string constant to a 'char*'
// //     std::cout << p << std::endl;
// //     return 0;
// // }

// // Pointer Addition
// // pointerAddition.cpp

// #include <iostream>

// int main()
// {
//     double a[] = {1.1, 2.2, 3.3, 4.4 , 5.5};
//     int i = 2;
//     double* p;

//     p = &a[1];
//     std::cout << std::hex;
//     std::cout << *p     << " : " << a     << std::endl;
//     std::cout << *(p + i) << " : " << p + i << std::endl;
//     std::cout << p[i]     << " : " << &p[i] << std::endl;
// }

// title.h

#include<iostream>
using namespace std;
class Title{
    const char* title;
    const char* validateTitle() const{
        if(!title[0]){
            throw "Invalid title";
        }
        else{
            return title;
        }
    }
    public:
    Title(const char* t): title(t) {}
    void display(){
        cout << validateTitle() << endl;
    }
};


template<typename T>
class SmartPtr{
    T* p{nullptr};
    public:
    SmartPtr(T* ptr): p(ptr) {};
    SmartPtr(const SmartPtr&) = delete;
    T* operator=(const SmartPtr&) = delete;
    SmartPtr(SmartPtr&& s) noexcept
    {
        p = s.p;
        s.p = nullptr;
    }
    SmartPtr& operator=(SmartPtr&& s) noexcept
    {
        if (this != &s)
        {
            delete p;
            p = s.p;
            s.p = nullptr;
        }
        return *this;
    }

    ~SmartPtr()
    {
        delete p;
    }

    T& operator*()
    {
        return *p;
    }

    T* operator->()
    {
        return p;
    }

};

void display(const char* t){
    SmartPtr<Title> title(new Title(t));
    title->display();
}
int main(){
    {
    const char* s[] = {"Mr.", "Ms.", "", "Dr."};

    for (auto x : s)
    {
        try
        {
            display(x);
        }
        catch(const char* msg)
        {
            std::cerr << msg << std::endl;
        }
    }
}
}