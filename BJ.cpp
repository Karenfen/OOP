// Author - Kiselev Ilia
// Game - Black Jack

#include <iostream>
#include <vector>

#define BJ 21
#define TEN 10

using namespace std;

enum SUIT {Trump, Clubs, Diamonds, Hearts, Spades};
string suit_name[] = {"Trump", "Clubs", "Diamonds", "Hearts", "Spades"};
enum VALUE {Joker, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
string value_name[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

class Card {
protected:
    VALUE m_value;
    SUIT m_suit;
    bool m_card_is_open;
public:
    Card(VALUE value, SUIT suit, bool card_is_open = true) : m_value(value), m_suit(suit), m_card_is_open(card_is_open) { }
    void Flip() { m_card_is_open = !m_card_is_open; }
    int GetValue() const { 
        if (m_card_is_open) 
            return m_value; 
        else 
            return 0;
    }
    friend ostream& operator<< (ostream &out, const Card &card);
    ~Card() { }
};

class Hand {
protected:
    vector<Card*>m_Cards;
public:
    Hand() { }
    ~Hand() { clear(); }
    void Add(Card* pCard) {
        m_Cards.push_back(pCard);
    }
    void clear() {
        if(m_Cards.empty())
            return;
        else {
            for (int index = 0; index < m_Cards.size(); index++) {
                delete m_Cards[index];
                m_Cards[index] = nullptr;
            }
            m_Cards.resize(0);
        }
    }
    int Get_Total() const {
        int Check = 0;
        int total = 0;
        for (int index = 0; index < m_Cards.size(); index++) {
            if (m_Cards[index]->GetValue() > TEN) {
                total += TEN;
            } else {
                total += m_Cards[index]->GetValue();
            }
            if (m_Cards[index]->GetValue() == Ace)
                Check++;
        }
        while (Check > 0) {
            if (total + TEN <= BJ && Check == 1) {
                total += TEN;
            }
            Check--;
        }
        return total;
    }
};

class Generic_Player : public Hand {
protected:
    string m_name;
public:
    Generic_Player() { };
    ~Generic_Player() { }
    virtual bool Is_Hitting() const = 0;
    bool Is_Busted() const {
        return Get_Total() > BJ;
    }
    void Bust() const {
        cout << "The player  " << m_name << " is BUST!" << endl;
    }
    friend ostream& operator<< (ostream &out, const Generic_Player &player);
};

class Player : public Generic_Player {
public:
    Player(const string &name) { Generic_Player::m_name = name; };
    ~Player() { };
    virtual bool Is_Hitting() const {
        char answer;
        cout << "One more card? (y/n): " << endl;
        cin >> answer;
        return (answer == 'y' || answer == 'Y');
    }
    void Win() const {
        cout << m_name << " is WIN !!!" << endl;
    }
    void Lose() const {
        cout << m_name << " is LOSE !!!" << endl;
    }
    void Push() const {
        cout << m_name << " is PUSH !!!" << endl;
    }
};

class House : public Generic_Player {
public:
    virtual bool IsHitting() const {
        return (Get_Total() <= 16);
    }
    void FlipFirstCard() {
        if (!m_Cards.front()->GetValue()) {
            m_Cards.front()->Flip();
        }  
    }
};

ostream& operator<< (ostream &out, const Card &card) {
    if (card.m_card_is_open) {
        out << value_name[card.m_value] << " " << suit_name[card.m_suit] << endl;
    } else {
        out << "XXX" << endl;
    }
    return out;
};

ostream& operator<< (ostream &out, const Generic_Player &player) {
    out << "Player: " << player.m_name << "\n";
    vector<Card*>::const_iterator it;
    it = player.m_Cards.begin();
    while (it != player.m_Cards.end()) {
        out << **it;
        ++it;
    }
    out << "Total score: " << player.Get_Total() << endl;
    return out;
};

int main (const int argc, const char **argv) {

    return 0;
}