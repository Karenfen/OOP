
#include "hand.hpp"
#include "generic_player.hpp"
#include "player.hpp"
#include "Class_game.hpp"
#include "func.hpp"

#include <vector>
#include <string>
#include <chrono>
#include <iostream>

using namespace std;

Game::Game(const vector<string>& names) {
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName) {
        m_Players.push_back(Player(*pName));
    }

    srand(static_cast<unsigned int>(time(0)));

    m_Deck.Populate();
    m_Deck.Shuffle();
}

Game::~Game() { }

void Game::Play(){
    vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i) {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
            m_Deck.Deal(*pPlayer);
        }

        m_Deck.Deal(m_House);
    }

    m_House.Flip_First_Card();

    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        cout << *pPlayer << endl;
    }
    cout << m_House << endl;

    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        m_Deck.Addltional_Cards(*pPlayer);
    }

    m_House.Flip_First_Card();
    cout << m_House << endl;

    m_Deck.Addltional_Cards(m_House);

    if (m_House.Is_Busted()) {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.begin(); ++pPlayer) {
            if (!(pPlayer->Is_Busted())){
                pPlayer->Win();
            }
        }
    }
    else {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
            if (!(pPlayer->Is_Busted())) {
                if (pPlayer->Get_Total() > m_House.Get_Total()) {
                    pPlayer->Win();
                }
                else if (pPlayer->Get_Total() < m_House.Get_Total()) {
                    pPlayer->Lose();
                }
                else {
                    pPlayer->Push();
                }
            }
        }
    }

    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        pPlayer->clear();
    }
    m_House.clear();
}
