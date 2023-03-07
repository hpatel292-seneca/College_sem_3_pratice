// in a class variable in class Item, count how many objects in the category ItemType::Gaming exist in the program (created but not yet destroyed)

// in a class variable in class Item, count how many discounted objects exists in the program (created but not yet destroyed). Note that the m_discount attribute can change during the lifetime of an object; this counter must be updated when an item becomes discounted or is not discounted anymore.

// add class functions to access the value of these counters
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include<string>
namespace sdds{
    enum class ItemType
{
    Clothing,
    Electronics,
    Appliance,
    Book,
    Movie,
    Computers,
    Tools,
    Gaming,
    Sports
};
class Item
{
    const ItemType m_category;
    std::string m_description{};
    std::string m_id{};
    double m_price{};
    double m_discount{};// a number in the interval [0, 1]
    
    public:
    static int NumOfGaming;
    Item(): m_category(ItemType::Book){
        m_price = 0;
    }
    ItemType getCategory() const;
    double getDiscount() const;
    void setDiscount(double num);
};
Item::NumOfGaming = 0;
ItemType Item::getCategory() const{
    return m_category;
}
double Item::getDiscount() const{
    return m_discount;
}
void Item::setDiscount(double num){
    m_discount = num;
}
}

#endif