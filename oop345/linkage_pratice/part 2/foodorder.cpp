#include<iostream>
#include<string>
#include<cstring>
#include "foodorder.h"
using namespace std;
using namespace sdds;

FoodOrder::FoodOrder(){
    m_desc = nullptr;
    m_is_special = false;
    m_name[0] = '\0';
    m_price = 0.0;
}

istream& FoodOrder::read(istream& istr){
    if (istr){
        string temp;
        char is_special;
        // int char_read{};
        istr.getline(m_name, MAX_CHAR_NAME, ',');

        // getline(istr, m_desc, ','); // way-1
        
        getline(istr, temp, ',');
        m_desc = new char[temp.length()];
        strcpy(m_desc, temp.c_str());

        istr >> m_price;
        istr.ignore();
        istr >> is_special;
        m_is_special = is_special == 'Y'? true : false; 
        istr.ignore(); 
    }
    return istr;
}

void FoodOrder::display(){
    static int times_called = 1;
    
    cout.width(2);
    cout.setf(ios::left);
    cout <<times_called;
    cout<< ". ";
    if(m_name[0] != '\0'){
        cout.width(10);
        cout << m_name;
        cout << "|";
        cout.width(25);
        cout << m_desc;
        cout << "|";
        cout.width(12);
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << m_price*(1+g_taxrate);
        cout<<"|";
        if(m_is_special){
            cout.setf(ios::right);
            cout.width(13);
            cout << m_price*(1+g_taxrate) - g_dailydiscount;
            cout.unsetf(ios::right);
        }
        cout<<endl;
    }
    else{
        cout << "No Order"<<endl;
    }
    times_called++;
}
FoodOrder::~FoodOrder(){
    delete[] m_desc;
}