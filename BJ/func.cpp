#include "Card.hpp"
#include "hand.hpp"
#include "generic_player.hpp"
#include "func.hpp"
#include <iostream>
#include <vector>

std::ostream& operator<< (std::ostream &out, const Card &card) {
    if (card.m_card_is_open) {
        out << value_name[card.m_value] << " " << suit_name[card.m_suit] << std::endl;
    } else {
        out << "XXX" << std::endl;
    }
    return out;
}

std::ostream& operator<< (std::ostream &out, const Generic_Player &player) {
    out << "Player: " << player.m_name << "\n";
    std::vector<Card*>::const_iterator it;
    it = player.m_Cards.begin();
    while (it != player.m_Cards.end()) {
        out << **it;
        ++it;
    }
    out << "Total score: " << player.Get_Total() << std::endl;
    return out;
}