#include"ShoppingCart.h"
namespace sdds{
    void ShoppingCart::add(const Item& src){
        // if (m_cnt > 0)
        // {
        //     Item* temp = m_pItems;
        //     m_pItems = new Item[m_cnt+1];
        //     for (size_t i = 0; i < m_cnt; i++)
        //     {
        //         m_pItems[i] = temp[i];
        //     }
        //     m_pItems[m_cnt] = src;
        //     m_cnt++;
        // }
        // else{
        //     m_pItems = new Item[1];
        //     m_pItems[0] = src;
        // }
    }
    void ShoppingCart::remove(const Item& src){
        bool found = true;
        int index = -1;
        for (size_t i = 0; i < m_cnt && found; i++)
        {
            if (m_pItems[i] == src)
            {
                index = 1;
                found = false;
            }
        }
        if (index != -1)
        {
            Item* temp = m_pItems;
            m_cnt--;
            m_pItems = new Item[m_cnt];
            
            int counterO = 0;
            int counterT = 0;
            while(counterO < m_cnt){
                if (counterO != index)
                {
                    m_pItems[counterO] = temp[counterT];
                    counterT++;
                    counterO++;
                }
                else{
                    counterT++;
                }
                
            }   
        }
    }

    void ShoppingCart::remove(ItemType type){
        for (size_t i = 0; i < m_cnt; i++)
        {
            if (m_pItems[i].getCategory() == type)
            {
                remove(m_pItems[i]);
            }
        }
        
    }

    void ShoppingCart::remove(){
        for (size_t i = 0; i < m_cnt; i++)
        {
            if (m_pItems[i].getDiscount() == 0.0)
            {
                remove(m_pItems[i]);
            }
        }
    }

    void ShoppingCart::update(ItemType type, double discount){
        for (size_t i = 0; i < m_cnt; i++)
        {
            if (m_pItems[i].getCategory() == type)
            {
                m_pItems[i].setDiscount(discount);
            }
        }
    }
}