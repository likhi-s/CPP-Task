#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <sstream>


using namespace std;
class Date
{
public:
    Date();
    ~Date();
    int getDay();
    int getMonth();
    int getYear();
    friend ostream &operator <<(ostream &out, Date &date);
    friend istream &operator >>(istream &in, Date &date);
    Date getCurrentDate();
    Date(int day, int month, int year);
    bool operator <(const Date &other) const;

private:
    int m_day;
    int m_month;
    int m_year;
};

#endif // DATE_H
