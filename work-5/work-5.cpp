// Author - Kiselev Ilia

#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>

#define BJ 21
#define TEN 10
using namespace std;

/// Classes and Functions for TASK-1 ///
template <class T>
class Pair1 {
private:
    T one;
    T two;
public:
    Pair1(T a, T b) : one(a), two(b) {  }
    T first() const { return one; }
    T second() const { return two; }
    ~Pair1() { }
};

/// Classes and Functions for TASK-2 ///
template <class T, class U>
class Pair {
private:
    T one;
    U two;
public:
    Pair(T a, U b) : one(a), two(b) {  }
    T first() const { return one; }
    U second() const { return two; }
    ~Pair() { }
};

/// Classes and Functions for TASK-3 ///
template <class V>
class Pair <string, V> {
private:
    string one;
    V two;
public:
    Pair(string a, V b) : one(a), two(b) { }
    string first() const { return one; }
    V second() const { return two; }
    virtual ~Pair() { }
};

template <class V>
class string_value_pair : public Pair <string, V>{
public:
    string_value_pair(string line, V value) : Pair<string, V>(line, value) { }
    ~string_value_pair() override { }
};

/// Classes and Functions for TASK-4 ///
enum SUIT {Trump, Clubs, Diamonds, Hearts, Spades};
string suit_name[] = {"Trump", "Clubs", "Diamonds", "Hearts", "Spades"};
enum VALUE {Joker, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
string value_name[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

class Card {
private:
    VALUE m_value;
    SUIT m_suit;
    bool m_card_is_open;
public:
    Card(VALUE value, SUIT suit, bool card_is_open = 0) : m_value(value), m_suit(suit), m_card_is_open(card_is_open) { }
    void Flip() { m_card_is_open = !m_card_is_open; }
    int GetValue() const { 
        if (m_card_is_open) 
            return m_value; 
        else 
            return 0;
    }
    ~Card() { }
};

class Hand {
private:
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
private:
    string m_name;
public:
    Generic_Player(string name) : m_name(name) { };
    ~Generic_Player() { }
    virtual bool Is_Hitting() const { };
    bool Is_Busted() const {
        if (Get_Total() > BJ)
            return true;
        else    
            return false;
    }
    void Bust() const {
        cout << "The player  " << m_name << " is BUST!" << endl;
    }
};

//// other function ////
void devide() {
    static int task = 0;
    cout << "\n|| Task - " << ++task << " ==============================================\n" << endl; 
}

int main (const int argc, const char **argv) {
	devide(); /// TASK-1 ///
{
    Pair1<int> p1(1, 2);
    cout << "Pair: " << p1.first() << " " << p1.second() << endl;
    Pair1<double> p2(1.11, 2.22);
    cout << "Pair: " << p2.first() << " " << p2.second() << endl;
}
    devide(); /// TASK-2 ///
{
    Pair<int, double> p1(1, 2.12);
    cout << "Pair: " << p1.first() << " " << p1.second() << endl;
    Pair<float, char> p2(1.1, 'k');
    cout << "Pair: " << p2.first() << " " << p2.second() << endl;
}
	devide(); /// TASK-3 ///
{
    string_value_pair<int> svp("Amazing", 7);
    cout << "Pair: " << svp.first() << " " << svp.second() << endl << endl;
}
    system("pause");
    return 0;
}