#pragma once
#include <vector>
#include <string>
#include "deck.hpp"
#include "house.hpp"

class Game {
public:
    Game(const std::vector<std::string>& names);
    ~Game();
    void Play();
private:
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;
};
