#pragma once

#include <vector>
#include "Card.hpp"

class Hand {
protected:
    std::vector<Card*>m_Cards;
public:
    Hand();
    virtual ~Hand();
    void Add(Card* pCard);
    void clear();
    int Get_Total() const;
};