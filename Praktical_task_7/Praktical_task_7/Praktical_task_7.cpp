#include <iostream>
#include <time.h>
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
<<<<<<< HEAD
    void setY(int y) {year=y; }//dddoOO
    ostream& operator<< (ostream& out , const Date& date)
    {
        out << "Date: " << date.m_day << ". " << date.m_month << ". " << date.m_year << "\n";
=======
    void setY(int y) {year=y; }
    friend ostream& operator<< (ostream& out, const Date& date);
    ostream& today(ostream& out, Date& date) {
        date.day = 14; date.month = 11; date.year=2021;
>>>>>>> refs/remotes/origin/main
        return out;
    }
    ~Date();
};
 ostream& operator<< (ostream& out , const Date& date)
    {
        out << "Date: " << date.day << ". " << date.month << ". " << date.year << "\n";
        return out;
    }
int main()
{
    Date D(12,11,2021);
    cout << D;
    
    cout << D.today();
}
