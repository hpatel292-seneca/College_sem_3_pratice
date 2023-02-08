// #include<string> // way-1
#ifndef SDDS_FOODORDER_H
#define SDDS_FOODORDER_H
#include<iostream>
    extern double g_taxrate;
    extern double g_dailydiscount ;

constexpr int MAX_CHAR_NAME = 10;
// constexpr int MAX_CHAR_DESC = 25;
namespace sdds{
    
    class FoodOrder{
        char m_name[MAX_CHAR_NAME]{};
        // std::string m_desc; // way-1
        char* m_desc{};
        double m_price{};
        bool m_is_special{};
        public: 
        FoodOrder();
        std::istream& read(std::istream& istr);
        void display();
        ~FoodOrder();
    };
}

#endif