#include "Card.hpp"
#include "enum.hpp"





Card::Card(VALUE value, SUIT suit, bool card_is_open) : m_value(value), m_suit(suit), m_card_is_open(card_is_open) { }

void Card::Flip() { m_card_is_open = !m_card_is_open; }

int Card::Get_Value() const {
    if (m_card_is_open)
        return m_value;
    else
        return 0;
}

Card::~Card() { }
