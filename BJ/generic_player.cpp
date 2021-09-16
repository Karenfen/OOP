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
