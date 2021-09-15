#include "Card.hpp"
#include "enum.hpp"
#include <string>


std::string suit_name[] = {"Trump", "Clubs", "Diamonds", "Hearts", "Spades"};
std::string value_name[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card(VALUE value, SUIT suit, bool card_is_open) : m_value(value), m_suit(suit), m_card_is_open(card_is_open) { }

void Card::Flip() { m_card_is_open = !m_card_is_open; }

int Card::Get_Value() const { 
    if (m_card_is_open) 
        return m_value; 
    else 
        return 0;
}

Card::~Card() { }
