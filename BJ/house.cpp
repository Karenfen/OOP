#include "hand.hpp"
#include "generic_player.hpp"
#include "house.hpp"

bool House::Is_Hitting() const {
    return (Get_Total() <= 16);
}

void House::Flip_First_Card() {
    m_Cards.front()->Flip();
}
House::~House() {}
House::House(const std::string& name) : Generic_Player(name) { }
