#pragma once

#include "enum.hpp"

class Card {
protected:
    VALUE m_value;
    SUIT m_suit;
    bool m_card_is_open;
public:
    Card(VALUE value, SUIT suit, bool card_is_open = true);
    void Flip();
    int Get_Value() const;
    friend std::ostream& operator<< (std::ostream &out, const Card &card);
    ~Card();
};