// Author - Ilia Kiselev
// Home Work - 7 : tasks 1-2

#include <memory>
#include <iostream>

using namespace std;

/// Classes and Functions for TASK-1 ///
class Date {
private:
    int day, month, year;
public:
    Date() : Date(01, 01, 2000) { };
    Date(int D, int M, int Y) : day(D), month(M), year(Y) { };
    ~Date() { };
    void Set_day(int D) { day = D; }
    void Set_month(int M) { month = M; }
    void Set_year(int Y) { year = Y; }
    int Get_day() const { return day; }
    int Get_month() const { return month; }
    int Get_year() const { return year; }
    friend ostream& operator<< (ostream &out, const Date &date);
    bool operator== (Date date2);
    bool operator> (Date date2);
    bool operator< (Date date2);
};

ostream& operator<< (ostream &out, const Date &date) {
    out << date.day << "/" << date.month << "/" << date.year;
}

bool Date::operator== (Date date2){
    return (this->year == date2.year && this->month == date2.month && this->day == date2.day);
};

bool Date::operator> (Date date2){
    if (this->year > date2.year)
        return true;
    else if (this->year < date2.year)
        return false;
    else {
        if (this->month > date2.month)
            return true;
        else if (this->month < date2.month)
            return false;
        else {
            if (this->day > date2.day)
                return true;
            else
                return false;
        }
    }
};

bool Date::operator< (Date date2){
    return (date2 > *this);
};

/// Classes and Functions for TASK-2 ///
Date& Comparison_dates(const unique_ptr<Date> &date1, const unique_ptr<Date> &date2) {
    if (*date1 > *date2)
        return *date1;
    else if (*date1 < *date2)
        return *date2;
    else {
        cout << "Same dates!" << endl;
        return *date1;
    }
}

void Swap_dates(unique_ptr<Date> &date1, unique_ptr<Date> &date2) {
    date1.swap(date2);
}

//// other function ////
void devide() {
    static int task = 0;
    cout << "\n|| Task - " << ++task << " ==============================================\n" << endl;
}

typedef unique_ptr<Date> DateUPtr;

int main (const int argc, const char **argv) {
    devide(); //// TASK-1
{
    DateUPtr date = make_unique<Date>();
    DateUPtr today = make_unique<Date>(11, 9, 2021);

    today->Set_day(11);
    today->Set_month(9);
    today->Set_year(2021);

    *date = *today.release();

    if ( date != nullptr)
        cout << "date: " << *date << endl;
    else
        cout << "date is null\n";

    if ( today != nullptr)
        cout << "date: " << *today << endl;
    else
        cout << "today is null\n";

}
    devide(); //// TASK-2
{
    DateUPtr date_1 = make_unique<Date>(9, 9, 2021);
    DateUPtr date_2 = make_unique<Date>(12, 9, 2021);

    cout << "Later date: " << Comparison_dates(date_1, date_2) << "\n" << endl;

    Swap_dates(date_1, date_2);

    cout << *date_1 << "\n" << *date_2 << "\n" << endl;
}
    system("pause");
    return 0;
}
