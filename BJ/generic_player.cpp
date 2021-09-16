#include "hand.hpp"
#include "generic_player.hpp"
#include "global.hpp"
#include <iostream>


Generic_Player::Generic_Player(const std::string &name) : m_name(name) { }

bool Generic_Player::Is_Busted() const {
    return (Get_Total() > BJ);
}

void Generic_Player::Bust() const {
    std::cout << "The player  " << m_name << " have BUST!" << std::endl;
}

Generic_Player::~Generic_Player(){ }

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
