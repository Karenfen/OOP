#include "generic_player.hpp"
#include "player.hpp"
#include <string>
#include <iostream>

bool Player::Is_Hitting() const {
    char answer;
    std::cout << m_name << ": one more card? (y/n): " << std::endl;
    std::cin >> answer;
    std::cout << std::endl;
    return (answer == 'y' || answer == 'Y');
}

void Player::Win() const {
    std::cout << m_name << " WIN !!!\n" << std::endl;
}

void Player::Lose() const {
    std::cout << m_name << " LOST !!!\n" << std::endl;
}

void Player::Push() const {
    std::cout << m_name << " PUSH !!!\n" << std::endl;
}