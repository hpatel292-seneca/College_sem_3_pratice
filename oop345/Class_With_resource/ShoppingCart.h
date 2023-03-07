// add items to the shopping cart
// remove items from the shopping cart
// rule-of-5 for the shopping cart
// remove from the shopping cart all items from a specified category (e.g., ItemType::Tools)
// remove from the shopping cart all items that don’t have a discount (discount is 0)
// update the discount on all items in a shopping cart that belong to a certain category (e.g., ItemType::Book)
// remove from the shopping cart all items that match a predicate received as a parameter (this is a lambda expression)
// print to screen the content of the shopping cart, formatted as a table

#ifndef SDDS_SHOPPINGCART_H
#define SDDS_SHOPPINGCART_H
#include "Item.h"
namespace sdds
{
    class ShoppingCart
    {
        Item *m_pItems{}; // a dynamically allocated array of items in the shopping cart
        size_t m_cnt{};

    public:
        void add(const Item& src);

        // remove items from the shopping cart
        void remove(const Item& src);
    };
}

#endif