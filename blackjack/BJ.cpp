// Author - Kiselev Ilia
// Game - Black Jack

#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <chrono>
#include <string>

using namespace std;

#define BJ 21
#define TEN 10

#include "Card.hpp"
#include "hand.hpp"
#include "generic_player.hpp"
#include "player.hpp"
#include "house.hpp"
#include "deck.hpp"
#include "func.hpp"
#include "Class_game.hpp"

int main (const int argc, const char **argv) {

    vector<string> players_names;
    string player_name;
    int players;
    char answer;

    cout << endl << "Enter the number of players: ";
    cin >> players;
    cout << endl;

    for (int i = 1; i <= players; ++i) {
        cout << "Enter player " << i << " name: ";
        cin >> player_name;
        cout << endl;

        players_names.push_back(player_name);
    }

    do {
        Game game_party(players_names);
        game_party.Play();

        cout << "Want to repeat? (y/Y to yes): ";
        cin >> answer;
        cout << endl;
    } while (answer == 'y' || answer == 'Y');
    
    return 0;
}