#include "hand.hpp"
#include "Card.hpp"
#include "global.hpp"

#include <vector>

Hand::Hand() { 
    m_Cards.reserve(7); 
}

Hand::~Hand() { 
    clear(); 
}

void Hand::Add(Card* pCard) {
    m_Cards.push_back(pCard);
}

void Hand::clear() {
    if(m_Cards.empty())
        return;
    else {
        for (int index = 0; index < m_Cards.size(); index++) {
            delete m_Cards[index];
            m_Cards[index] = nullptr;
        }
        m_Cards.resize(0);
    }
}

int Hand::Get_Total() const {
        int Check = 0;
        int total = 0;
        for (int index = 0; index < m_Cards.size(); index++) {
            if (m_Cards[index]->Get_Value() > TEN) {
                total += TEN;
            } else {
                total += m_Cards[index]->Get_Value();
            }
            if (m_Cards[index]->Get_Value() == Ace )
                Check++;
        }
        while (Check > 0) {
            if (total + TEN <= BJ && Check == 1) {
                total += TEN;
            }
            Check--;
        }
        return total;
    }