// Author - Kiselev Ilia

#include <cstring>
#include <iostream>
#include <cmath>
#include <cassert>

#define PI 3.1415926535
using namespace std;

/// TASK-1  ////==========================
class Figure
{
public:
    virtual double area() const = 0;
};

class Circle : public Figure
{
private:
    double R;
public:
    Circle(double r) : R(r) { 
        //cout << "Circle" <<  endl;
    }
    double area() const override {
        return R*R*PI;
    }
    ~Circle() {
        //cout << "~Circle" <<  endl;
     }
};

class Parallelogram :  public Figure
{
private:
    double base, edge;
    int angle;
public:
    Parallelogram(double ba, double ed, int an) : base(ba), edge(ed), angle(an) { 
        //cout << "Parralelogram" <<  endl;
    }
    double area() const override { 
        double radian = angle / 180.0 * PI;
        return base * edge * sin(radian); 
    };
    virtual ~Parallelogram() { 
        //cout << "~Parralelogram" <<  endl;
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(double ba, double ed) : Parallelogram(ba, ed, 90) { 
        //cout << "Rectangle" <<  endl;
    }
    ~Rectangle() override { 
        //cout << "~rectangle" <<  endl;
    }
};

class Square : public Parallelogram 
{
public:
    Square(double side) : Parallelogram(side, side, 90) { 
        //cout << "square" <<  endl;
    }
    ~Square() override { 
        //cout << "~square" <<  endl;
    }
};

class Rhombus : public Parallelogram 
{
public:
    Rhombus(double side, int an) : Parallelogram(side, side, an) { 
        //cout << "Romb" <<  endl;
    }
    ~Rhombus() override { 
       // cout << "~Romb" <<  endl;
    }
};

/// TASK-2  ////==========================
class Car
{
private:
    string company;
    string model;
public:
    Car() { 
        cout << "Car. " << endl; 
    }
    Car(string comp, string mod) :company(comp), model(mod) { 
        cout << "======================" << endl;
        cout << "Car: " << company << " " << model << endl; 
    }
    ~Car() { }
};

class PassengerCar : virtual public Car
{
public:
    PassengerCar() { 
        cout << "Type: PassengerCar" << endl; 
    }
    PassengerCar(string comp, string mod) : Car(comp, mod) { 
        cout << "Type: PassengerCar" << endl; 
    }
    ~PassengerCar() { }
};

class Bus : virtual public Car
{
public:
    Bus() {
        cout << "Type: Bus" << endl; 
    }
    Bus(string comp, string mod) : Car(comp, mod) {
        cout << "Type: Bus" << endl; 
    }
    ~Bus(){ }
};

class Minivan : public PassengerCar, Bus
{
public:
    Minivan(string comp, string mod) : 
    Bus(comp, mod), PassengerCar(comp, mod) , Car(comp, mod) {
        cout << "Type: Minivan" << endl; 
    }
    ~Minivan() { }
};

/// TASK-3  ////==========================
class Fraction
{
private:
    int numerator, denominator;
public:
    Fraction(int numer, int denom) : numerator(numer) {
        if(denom != 0) { denominator = denom; }
        else { cout << "Wrong denominator! Enter a non-zero value." << endl;}
    }
    void print() const { 
        cout << numerator << "/" << denominator ; 
    }
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
    void setDenominator(int denom) { 
        if(denom != 0) { denominator = denom; }
        else { cout << "Wrong denominator! Enter a non-zero value." << endl;}
    }
    Fraction operator-() const { return Fraction(-numerator, denominator); }
    friend bool operator< (Fraction &f1, Fraction &f2);
    friend bool operator> (Fraction &f1, Fraction &f2);
    friend bool operator<= (Fraction &f1, Fraction &f2);
    friend bool operator>= (Fraction &f1, Fraction &f2);
    ~Fraction() { }
};

bool operator< (Fraction &f1, Fraction &f2) {
    double val_1 = 1.0 * f1.numerator / f1.denominator;
    double val_2 = 1.0 * f2.numerator / f2.denominator;
    return (val_1 < val_2);
}

bool operator> (Fraction &f1, Fraction &f2) {
    double val_1 = 1.0 * f1.numerator / f1.denominator;
    double val_2 = 1.0 * f2.numerator / f2.denominator;
    return (val_1 > val_2);
}

bool operator>= (Fraction &f1, Fraction &f2) {
    return (!(f1 < f2));
}

bool operator<= (Fraction &f1, Fraction &f2) {
    return (!(f1 > f2));
}

Fraction operator+ (const Fraction &f1, const Fraction &f2) {
    int numer, denom;
    numer = f1.getNumerator() * f2.getDenominator() + f2.getNumerator() * f1.getDenominator();
    denom = f1.getDenominator() * f2.getDenominator();
    return Fraction(numer, denom);
}

Fraction operator- (const Fraction &f1, const Fraction &f2) {
    int numer, denom;
    numer = f1.getNumerator() * f2.getDenominator() - f2.getNumerator() * f1.getDenominator();
    denom = f1.getDenominator() * f2.getDenominator();
    return Fraction(numer, denom);
}

Fraction operator* (const Fraction &f1, const Fraction &f2) {
    int numer, denom;
    numer = f1.getNumerator() * f2.getNumerator();
    denom = f1.getDenominator() * f2.getDenominator();
    return Fraction(numer, denom);
}

Fraction operator/ (const Fraction &f1, const Fraction &f2) {
    int numer, denom;
    numer = f1.getNumerator() * f2.getDenominator();
    denom = f1.getDenominator() * f2.getNumerator();
    return Fraction(numer, denom);
}

/// TASK-3  ////==========================
enum SUIT {Trump, Clubs, Diamonds, Hearts, Spades};
enum VALUE {Joker, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, 
            Jack = 10, Queen = 10, King = 10};
class Card
{
private:
    VALUE value;
    SUIT suit;
    bool state;
public:
    Card(VALUE val, SUIT ST, bool stt = 0) : value(val), suit(ST), state(stt) { }
    void Flip() { state = !state; }
    int GetValue() const { return value; }
    ~Card() { }
};

//// OTHER  //// =========================
void devide() {
    static int task = 0;
    cout << "\n|| Task - " << ++task << " ==============================================\n" << endl; 
}
///// BODY //// ==============================================================================
int main(const int argc, const char** argv) {
    devide();  /* TASK-1 */
    {
        Figure *figure_1 = new Circle(12);
        Figure *figure_2 = new Rhombus(12, 35);
        Figure *figure_3 = new Square(12);
        Figure *figure_4 = new Rectangle(12, 7);
        Figure *figure_5 = new Parallelogram(12, 5, 35);

        cout << "Area of circle: " << figure_1->area() << endl;
        cout << "Area of romb: " << figure_2->area() << endl;
        cout << "Area of square: " << figure_3->area() << endl;
        cout << "Area of rectangle: " << figure_4->area() << endl;
        cout << "Area of parallelogram: " << figure_5->area() << endl;

        delete figure_1;
        delete figure_2;
        delete figure_3;
        delete figure_4;
        delete figure_5;
    }    
    devide();  /* TASK-2 */
    {
        Car car_1("toyota", "sprinter");
        PassengerCar car_2("toyota", "corrola");
        Bus car_3("VAZ", "2101");
        Minivan car_4("volkswagen", "multivan");
    }
    devide();  /* TASK-3 */
    {
        Fraction num_1(5, 9);
        Fraction num_2(3, 4);
        Fraction sum = num_1 + num_2;
        num_1.print();
        cout << " + ";
        num_2.print();
        cout << " = ";
        sum.print(); 
        cout << endl;

        Fraction minus = num_1 - num_2;
        num_1.print();
        cout << " - ";
        num_2.print();
        cout << " = ";
        minus.print(); 
        cout << endl;

        Fraction multi = num_1 * num_2;
        num_1.print();
        cout << " * ";
        num_2.print();
        cout << " = ";
        multi.print(); 
        cout << endl;

        Fraction division = num_1 / num_2;
        num_1.print();
        cout << " / ";
        num_2.print();
        cout << " = ";
        division.print(); 
        cout << endl;

        Fraction negative = -minus;
        cout << "- ( ";
        minus.print();
        cout << " ) = ";
        negative.print();
        cout << endl;
        
        num_1.print();
        if(num_1 < num_2) {
            cout << " < ";
        } else {
            cout << " >= ";
        }
        num_2.print();
        cout << endl;

        num_2.print();
        if(num_2 <= num_1) {
            cout << " <= ";
        } else {
            cout << " > ";
        }
        num_1.print();
        cout << endl;


    }
    devide();  /* TASK-4 */
    {
        Card card_1(Four, Diamonds);
        Card card_2(Queen, Hearts);
        int sum = card_1.GetValue() + card_2.GetValue();
        cout << "Four + Queen = " << sum << " points\n" << endl;
    }
    system("pause");
    return 0;
}

