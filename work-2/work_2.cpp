// Author - Kiselev Ilia

#include <iostream>
#include <cstring>

#define SIZE 10
using namespace std;

// class Stack 
//{    
// private:
//     const Student* arr[SIZE];
//     int lenght;
// public:
//     ~Stack()
//     {
//         free(arr);
//     }
//     void reset(){
//         lenght = 0;
//         for(int i = 0; i < SIZE; i++){
//             arr[i] = NULL;
//         }
//     }
//     bool push(const Student* student){
//         if(lenght == SIZE)
//             return false;
//         arr[lenght++] = student;
//         return true;
//     }
//     bool pop(){
//         if(lenght == 0) {
//             cout << "Stack is empty!" << endl;
//             return false;
//         } else {
//             arr[--lenght] = nullptr;
//             return true;
//         }
//     }
// };

class Person //// TASK-1
{    
protected:
    string name;
    int age;
    const string gender;
    double weight;
public:
    Person(const string GN = "NON", string NM = "NON", int AG = 0, double WG = 0) : name(NM), age(AG), gender(GN), weight(WG) { /* cout << "Person" << endl; */ }
    void setName(string NM) { name = NM; }
    string getName() const { return name; }
    void setAge(int AG) { age = AG; }
    int getAge () const { return age; }
    void setWeight(double WG) { weight = WG; }
    double getWeight() const { return weight; }
    friend void print(const Person &person);
    ~Person() { /*cout << "~Person" << endl; */ }
};

class Student: public Person {
private:
    //static Student* arr[SIZE];
    static int counter;
    int yearStudy;
public:
    Student(const string GN = "NON", string NM = "NON", int AG = 0, double WG = 0, int YS = 0) : Person(GN, NM, AG, WG), yearStudy(YS) 
    {
        counter++;
        //arr[counter++] = this;
        //Stack::push(this);
        //cout << "Student" << endl;
    }
    void setYearStudy(int year) { yearStudy = year; }
    void increaseYS() { yearStudy++; }
    //friend Student& search(string name);
    friend void print(const Student &student);
    friend int getCounter();
    ~Student(){
        counter--;
        //arr[--counter] = NULL;
        //cout << "~Student" << endl;
    }
};

int Student::counter = 0;
int getCounter() { return Student::counter; }
void print(const Student &student) 
{
    cout << "Student name: " <<  student.name << "\n" << "Gender: " << student.gender << "\n" << "Age: " << student.age << " years\n" << 
    "Weight: " << student.weight << " kg.\n" << "Year of study: " << student.yearStudy << " year." << endl;
}
// Student& search(string name) 
//{
//     for (int i = 0; i < getCounter(); i++){
//         if (Student::arr[i]->name == name){
//             Student& p = *Student::arr[i];
//             return p;
//         }
//     }
//     cout << "Еhere is no student with that name!" << endl;
// };
// void print(const Person &person) 
//{
//     cout << "Student name: " <<  person.name << "\n" << "Gender: " << person.gender << "\n" << "Age: " << person.age << " years\n" << 
//     "Weight: " << person.weight << " kg.\n" << endl;
// }

class Fruit
{
protected:
    string name;
    string color;
public:
    Fruit(string NM = "other", string CLR = "other") : name(NM), color(CLR) { }
    void setName(string NM) { name = NM; }
    void setColor(string CLR) { color = CLR; }
    string getName() const { return name; }
    string getColor() const { return color; }
    void print() const
    {
        cout << "Fruit: " << name << "\n" << "Color: " << color << endl;
    }
    ~Fruit() { }
};

class Apple : public Fruit
{
public:
    Apple(string CLR, string NM = "apple") : Fruit(NM, CLR) { }
    ~Apple() { }
};

class Banana : public Fruit
{
public:
    Banana(string CLR = "yelow") : Fruit("banana", CLR) { }
    ~Banana() { }
};

class GrannySmith : public Apple
{
public:
    GrannySmith() : Apple("green", "GrannySmith") {   }
    ~GrannySmith(){ }
};

void devide()
{
    static int task = 0;
    cout << "\n|| Task - " << ++task << " ==============================================\n" << endl; 
}

int main (const int argc, const char**argv){
    devide(); //// TASK-1
{
    Student Ivan("male");
    Ivan.setName("Ivanov Ivan Ivanovich");
    Ivan.setAge(23);

    Student Ilia("male", "Kiselev Ilia Aleksandrovich", 27, 65, 2020);

    Student Sasha("female", "Alecksandra Alecksandovna Gray", 18);
    Sasha.setYearStudy(2000);

    print(Ilia);

    // string name = "Ivanov Ivan Ivanovich";
    // print(search(name));
    //cout << getCounter() << endl;

}
    devide(); //// TASK-2
{
    Apple a("red");
    Banana b;
    GrannySmith c;
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n" << endl;
}
system("pause");
return 0;
}