#include "hand.hpp"
#include "generic_player.hpp"
#include "deck.hpp"
#include <random>
#include <chrono>
#include <algorithm>

Deck::Deck() { 
    m_Cards.reserve(52);
    Populate(); 
}

Deck::~Deck() { }

void Deck::Populate() {
    clear();

    for (int suit = Clubs; suit <= Spades; ++suit) {
        for (int value = Ace; value <= King; ++value) {
            Add(new Card(static_cast<VALUE>(value), static_cast<SUIT>(suit)));
        }
    }
}

void Deck::Shuffle() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(m_Cards.begin(), m_Cards.end(), std::default_random_engine(seed));
}

void Deck::Deal (Hand& aHand) {
    if (!m_Cards.empty()) {
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
    else {
        std::cout << "Out of cards. Unable to deal.";
    }
}

void Deck::Addltional_Cards (Generic_Player& a_Generlc_Player) {
    std::cout << std::endl;
    while (!(a_Generlc_Player.Is_Busted()) && a_Generlc_Player.Is_Hitting()) {
        Deal(a_Generlc_Player);
        std::cout << a_Generlc_Player << std::endl;

        if (a_Generlc_Player.Is_Busted()) {
            a_Generlc_Player.Bust();
        }
    }
}
