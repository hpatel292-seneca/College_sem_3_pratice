// Create a family of class named Collection (a template class) that manages a dynamically allocated collection of items of any type. The class should support the following operations:
// create an empty collection
// rule-of-5
// add an item
// remove an item
// retrieve the item at a specified index
// modify the item from a specified index
// print the content of the collection to screen
// // remove all items
// remove all items that match a certain condition (a lambda expression received from the client as a parameter)
// create a new collection that contains only items that match a certain condition (a lambda expression received from the client as a parameter)
// The class should use exceptions to inform the client when an operation cannot be completed (e.g., bad parameters)
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include<iostream>
#include<functional>

namespace sdds{
    template<typename T>
    class Collection{
        T* m_items{};
        int m_size{};
        public:
        Collection();
        // Rule of five
        // copy Constructor
        Collection(const Collection<T>& src);
        // copy assisgnment
        Collection<T>& operator=(const Collection<T>& src);
        // destructor
        ~Collection();
        // move Constructor
        Collection(Collection<T>&& src);
        // move assisgnment
        Collection<T>& operator=(Collection<T>&& src);

        // add an it
        void operator++(T& item);

        // retrieve the item at a specified index
        const T& operator[](const int& index) const;

        // print the content of the collection to screen
        void display() const;

        // remove all items
        void remove();

        // remove all items that match a certain condition (a lambda expression received from the client as a parameter)
        void remove_if(std::function<bool(T&)> test);
    };

     template<typename T>
     Collection<T>::Collection(){
         m_item = nullptr;
         m_size = 0;
     }

     template <typename T>
     inline Collection<T>::Collection(const Collection<T>& src)
     {
        *this = src;
     }

     template<typename T>
     Collection<T>& Collection<T>::operator=(const Collection<T>& src){
        // step-1 check for self assignment
        if (this != &src)
        {
            // step-2 clean up
            delete[] m_items;

            // step-3 shallow copy
            m_size = src.m_size;

            // step-4 deep copy
            if (m_size > 0)
            {
                m_item = new T[m_size];
                for (size_t i = 0; i < m_size; i++)
                {
                    m_item[i] = src.m_items[i];
                }
            }
        }
     }

    template<typename T>
    Collection<T>::~Collection(){
        delete[] m_items;
    }

    template<typename T>
    Collection<T>::Collection(Collection<T>&& src){
        *this = src;
    }

    template<typename T>
    Collection<T>& Collection<T>::operator=(Collection<T>&& src){
        // step-1 check for self assignment
        if (this != &src)
        {
            // step-2 clean up
            delete[] m_items;

            // step-3 shallow copy
            m_size = src.m_size;

            // step-4 deep copy
            if (m_size > 0)
            {
                m_items = src.m_items;
                src.m_items = nullptr;
                src.m_items = 0;
            }
        }
    }

    template<typename T>
    void Collection<T>::operator++(T& item){
        if (size > 0)
        {
            T* temp = m_items;
            m_items = new T[m_size+1];
            for (size_t i = 0; i < m_size; i++)
            {
                m_items[i] = m_temp[i];
            }
            m_items[m_size] = item;
            m_size++;
        }
        else{
            m_items = new T[1];
            m_items[0] = item;
        }
        
    }

    template<typename T>
    const T& Collection<T>::operator[](const int& index) const{
        return m_items[index];
    }

    template<typename T>
    void Collection<T>::display() const{
        for (size_t i = 0; i < m_size; i++)
        {
            std::cout << m_items[i] << std::endl;
        }
        
    }

    template<typename T>
    void Collection<T>::remove(){
        delete[] m_items;
        m_size = 0;
    }
    template <typename T>
    inline void Collection<T>::remove_if(std::function<bool(T&)> test)
    {
        
    }
}

#endif