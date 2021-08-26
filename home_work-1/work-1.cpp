// Author - Ilia Kiselev

#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdint>

using namespace std;
#define SIZE 10

class Power {      //// TASK-1
    double number;
    double degree;
public:
    Power() : number(1), degree(1) {
        cout << "Power: " << endl;
    }
    Power(double num, double deg) : number(num), degree(deg) {
        cout << "Power: " << endl;
    }
    void set(double num, double deg){
        assert(deg > 0);

        number = num;
        degree = deg;
    }
    ~Power(){
       // cout << "Clear..." << endl;
    }
    void calculate(){
        cout << number << " to the power of " << degree << " = "<< pow(number, degree) << endl;
    }
};

class RGBA {      //// TASK-2
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
public:
    RGBA() : m_alpha(255), m_blue(1), m_green(1), m_red(1){

    }
    RGBA(uint8_t m_r, uint8_t m_g, uint8_t m_b, uint8_t m_a = 255) : m_alpha(m_a), m_blue(m_b), m_green(m_g), m_red(m_r){

    }
    void print(){
        printf("red: %d, green: %d, blue: %d, alpha: %d\n", m_red, m_green, m_blue, m_alpha);       
    }
};

class Stack {     //// TASK-3
private:
    int arr[SIZE];
    int lenght;
public:
    ~Stack(){
        free(arr);
    }
    void reset(){
        lenght = 0;
        for(int i = 0; i < SIZE; i++){
            arr[i] = 0;
        }
    }
    bool push(int val){
        if(lenght == SIZE)
            return false;
        arr[lenght++] = val;
        return true;
    }
    int pop(){
        if(lenght == 0) {
            cout << "Stack is empty!" << endl;
        } else {
            return arr[--lenght];
        }
    }
    void print(){
        cout << "Lenght: " << lenght << endl;
        cout << "( ";
        for(int i = 0; i < lenght; i++){
            cout << arr[i] << " ";
        }
        cout << ")" << endl;
    }
};

int main (const int argc, const char** argv){
    cout << endl << "TASK-1 ===========================================" << endl << endl; /// start of the task-1
    {
    Power test_1;
    test_1.calculate();
    
    Power test_2;
    test_2.set(5, 3);
    test_2.calculate();

    Power test_3(1.5, 5.36);
    test_3.calculate();
    }
    cout << endl << "TASK-2 ===========================================" << endl << endl; /// start of the task-2
    {
    RGBA test_1;
    test_1.print();
    RGBA test_2(5, 10, 25);
    test_2.print();
    }
    cout << endl << "TASK-3 ===========================================" << endl << endl; /// start of the task-3
    {
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(5);
    stack.push(7);
    stack.push(9);
    stack.push(1);
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
    stack.reset();
    stack.print();
    }
    cout << endl;
    system("pause");
    return 0;
}