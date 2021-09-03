// Author - Kiselev Ilia

#include <vector>
#include <iostream>
#include <cstring>
#include <cassert>

#define BJ 21
using namespace std;

/// Classes and Functions for TASK-1 ///
class  Array_int{
private:
    int m_lenght;
    int* m_data;
public:
    Array_int() : m_lenght(0), m_data(nullptr) { }
    Array_int(int lenght) : m_lenght(lenght) {
        assert(lenght >= 0);

        if (lenght > 0) {
            m_data = new int[lenght];
            zeroing();
        }
        else
            m_data = nullptr;
    }
    ~Array_int() {
        delete m_data;
    }
    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_lenght = 0;
    }
    void zeroing() {
        for (int index = 0; index < m_lenght; index++) {
            m_data[index] = 0;
        }
    }
    int get_lenght() const { return m_lenght; }
    int& operator[] (int index) {
        assert(index >= 0 && index < m_lenght);
        return m_data[index];
    }
    void resize(int new_lenght) {
        if (new_lenght == m_lenght)
            return;
        if (new_lenght <= 0) {
            erase();
            return;
        }

        int* data = new int[new_lenght];

        if (m_lenght > 0) {
            int elements_to_copy = (new_lenght > m_lenght) ? m_lenght : new_lenght;

            for (int index = 0; index < elements_to_copy; index++) {
                data[index] = m_data[index];
            }
        }

        delete[] m_data;
        m_data = data;
        m_lenght = new_lenght;
    }
    void insert_before(int value, int index) {
        assert(index >= 0 && index <= m_lenght);

        int* data = new int[m_lenght + 1];

        for (int before = 0; before < index; before++) {
            data[before] = m_data[before];
        }

        data[index] = value;

        for (int after = index; after < m_lenght; after++) {
            data[after + 1] = m_data[after];
        }

        delete[] m_data;
        m_data = data;
        m_lenght++;
    }
    void push_back(int value) { insert_before(value, m_lenght);  }
    void push_front(int value) { insert_before(value, 0);  }
    void pop_back() {
        resize(m_lenght - 1);
    }
    void pop_front() {
        if ( m_lenght == 0) 
            return;
        if ( m_lenght == 1 ) {
            erase();
            return;
        }

        int* data = new int[m_lenght - 1];

        for (int index = 1; index < m_lenght; index++) {
            data[index - 1] = m_data[index];
        } 

        delete[] m_data;
        m_data = data;
        m_lenght--;
    }
    void swap(int from, int to){
        int value = m_data[from];
        m_data[from] = m_data[to];
        m_data[to] = value;
    }
    void sort(){
        for(int j = 0; j < m_lenght; j++){
            for (int i = 0; i < m_lenght - 1 - j; i++){
                if (m_data[i] > m_data[i + 1]){
                    swap(i, i + 1);
                }
            }
        }
    }
    void print() const {
        for ( int index = 0; index < m_lenght; index++) {
            cout << m_data[index] << "  ";
        }
        cout << endl;
    }

};

/// Classes and Functions for TASK-2 ///
int checking_for_unique_numbers(vector<int> &p) {
    int total = 0;
    int *array = new int[p.size()];
    vector<int>::const_iterator it;
    it = p.begin();

    while ( it != p.end()) {
        bool check = true;
        for (int index = 0; index < total; index++){
            if ( *it == array[index]) {
                check = false;
                break;
            }     
        }
        if (check) {
            array[total++] = *it;
        }
        it++;
    }

    return total;
}

/// Classes and Functions for TASK-3 ///
enum SUIT {Trump, Clubs, Diamonds, Hearts, Spades};
enum VALUE {Joker, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack = 10, Queen = 10, King = 10};

class Card {
private:
    VALUE m_value;
    SUIT m_suit;
    bool m_card_is_open;
public:
    Card(VALUE value, SUIT suit, bool card_is_open = 0) : m_value(value), m_suit(suit), m_card_is_open(card_is_open) { }
    void Flip() { m_card_is_open = !m_card_is_open; }
    int GetValue() const { return m_value; }
    ~Card() { }
};

class Hand {
private:
    vector<Card*>m_Cards;
public:
    Hand() { }
    ~Hand() { }
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
            total += m_Cards[index]->GetValue();
            if (m_Cards[index]->GetValue() == Ace)
                Check++;
        }
        while (Check > 0) {
            if (total + 10 <= BJ && Check == 1) {
                total += 10;
            }
            Check--;
        }
        return total;
    }
};

//// other function ////
void devide() {
    static int task = 0;
    cout << "\n|| Task - " << ++task << " ==============================================\n" << endl; 
}

int main (const int argc, const char** argv) {
	devide(); /// TASK-1 ///
{
    Array_int array(10);
    array.print();
    array[2] = 8;
    array[3] = 1;
    array[5] = 12;
    array[8] = 7;
    array[6] = 3;

    array.sort();
    cout << "lenght: " << array.get_lenght() << endl;
    array.print();
    array.pop_front();
    array.pop_front();
    array.pop_back();
    cout << "lenght: " << array.get_lenght() << endl;
    array.print();
    array.push_back(20);
    cout << "lenght: " << array.get_lenght() << endl;
    array.print();
    array.insert_before(15, 1);
    array.push_front(5);
    cout << "lenght: " << array.get_lenght() << endl;
    array.print();
}
    devide(); /// TASK-2 ///
{
    vector<int> numbers {0, 1, 2, 3, 4, 5, 5, 4};
    for ( int index = 0; index < numbers.size(); index++) {
        cout << numbers[index] << "  ";
    }
    cout << endl;
    cout << "unique numbers: " << checking_for_unique_numbers(numbers) << endl << endl;

}
system("pause");
return 0;
}