// Author - Ilia Kiselev

#include <iostream>

using namespace std;

/// Task - 1 ///
template <typename T>
T div(T num1, T num2) 
{
    if ( num2 == 0 ) {
        throw 0;
    }
    return (num1 / num2);
}

/// Task - 2 ///
class Ex
{
private:
    float x;
public:
    Ex(float number);
    float what() const;
};

Ex::Ex(float number) : x(number) { }

float Ex::what() const
{
    return x;
}

class Bar
{
private:
    float y;
public:
    Bar();
    void set(float a);
};

Bar::Bar() : y(0) { }

void Bar::set(float a)
{
    if (y + a > 100) 
    {
        throw Ex(y*a);
    }
    y = a;
}

/// Task - 3 ///
class IllegalCommand
{
protected:
    int curent_posX;
    int curent_posY;
    int m_routeX;
    int m_routeY;
public:
    IllegalCommand(int posX, int posY, int routeX, int routeY);
    void what() const;
};

IllegalCommand::IllegalCommand(int posX, int posY, int routeX, int routeY) :
    curent_posX(posX), curent_posY(posY),
    m_routeX(routeX), m_routeY(routeY) { }

void IllegalCommand::what() const
{
    cout << "Curent position: ( " << (curent_posX + 1) << " , " << (curent_posY + 1) << " )\n";
    cout << "Move to: ( " << (curent_posX + m_routeX + 1) << " , " << (curent_posY + m_routeY + 1) << " )\n"; 
}

class OffTheField : public IllegalCommand
{
private:
    int m_maxSize;
public:
    OffTheField(int posX, int posY, int routeX, int routeY, int max);
    void what() const;
};

OffTheField::OffTheField(int posX, int posY, int routeX, int routeY, int max) : IllegalCommand(posX, posY, routeX, routeY), m_maxSize(max) { }

void OffTheField::what() const
{
    IllegalCommand::what();
    cout << "fild ( " << m_maxSize << " X " << m_maxSize << " )\n";
}

class Robot
{
private:
    const int MAX = 10;
    //int field[MAX][MAX] = {0};
    int m_posX;
    int m_posY;
public:
    Robot();
    void move(int x, int y);
    void print() const;
};

Robot::Robot() : m_posX(0), m_posY(0) { }

void Robot::print() const
{
    for (int i = 0; i < 10; ++i) 
    {
        for (int j = 0; j < 10; ++j)
        {
            if (i == m_posY && j == m_posX)
                cout << "R ";
            else 
                cout << "_ ";
        }
        cout << endl;
    }
    cout << endl;
}

void Robot::move(int x, int y) 
{
    if ((x > 1 || x < -1) || (y > 1 || y < -1))
    {
        throw IllegalCommand(m_posX, m_posY, x, y);
    }
    else if (((m_posX + x >= 10) || (m_posX + x < 0)) || ((m_posY + y >= 10) || (m_posY + y < 0)))
    {
        throw OffTheField(m_posX, m_posY, x, y, MAX);
    }
    else 
    {
        m_posX += x;
        m_posY += y;
    }
}

//// other function ////
void devide() {
    static int task = 0;
    cout << "\n|| Task - " << ++task << " ==============================================\n" << endl; 
}

int main (const int argc, const char** argv) {
    devide();  /// TASK-1 ///
{
    double num_1 = 5, num_2 = 0;

    try
    {
       double number = div(num_1, num_2);
       cout << num_1 << " / " << num_2 << " = " << number << endl;
    }
    catch(int zero)
    {
        cerr << "ERROR! invalid divider:  " << zero << '\n';
    }
    
}
    devide();  /// TASK-2 ///
{
    Bar check;
    float n;

    do
    {
        cout << "Enter a number: ";
        cin >> n;

        try
        {
            check.set(n);
        }
        catch(const Ex& err)
        {
            cerr << "ERROR " << err.what() << '\n';
        }
        
    } while (n != 0);
}
    devide();  /// TASK-3 ///
{
    Robot robot;
    robot.print();
    int moveX, moveY;
    do
    {
        cout << "Enter the direction of travel: ";
        cin >> moveX >> moveY;
        try
        {
            robot.move(moveX, moveY);
        }
        catch(const OffTheField& e)
        {
            cerr << "OffTheField!\n";
            e.what();
        }
        catch(const IllegalCommand& e)
        {
            cerr << "IllegalCommand!\n";
            e.what();
        }
        robot.print();

    } while (moveX != 0 || moveY != 0);
    
}
    system("pause");
    return 0;
}
