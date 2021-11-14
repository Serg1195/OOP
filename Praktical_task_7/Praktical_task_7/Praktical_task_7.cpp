#include <iostream>
using namespace std;
class Date {
    int day, month, year;
public:
    Date(int d, int m, int y) { day = d; month = m; year = y; }
    int getD() const { return day; }
    int getM() const { return month; }
    int getY() const { return year; }
    void setD(int d) { day=d; }
    void setM(int m) {month=m; }
    void setY(int y) {year=y; }
    ostream& operator<< (ostream& out , const Date& date)
    {
        out << "Date: " << date.m_day << ". " << date.m_month << ". " << date.m_year << "\n";
        return out;
    }


};
int main()
{
    Date D(14,11,2021);
    cout << D;
}
