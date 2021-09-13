#include "hand.hpp"
#include "generic_player.hpp"
#include "house.hpp"

bool House::Is_Hitting() const {
    return (Get_Total() <= 16);
}

void House::Flip_First_Card() {
    if (!Hand::m_Cards.front()->Get_Value()) {
        m_Cards.front()->Flip();
    }  
}
