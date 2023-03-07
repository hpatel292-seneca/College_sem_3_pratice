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
}
class Item
{
    const ItemType m_category;
    std::string m_description{};
    std::string m_id{};
    double m_price{};
    double m_discount{};// a number in the interval [0, 1]
    // ...
}
class ShoppingCart
{
    Item* m_pItems{}; // a dynamically allocated array of items in the shopping cart
    size_t m_cnt{};
    // ...
}