
#include <iostream>
using namespace std;
template<class T>//
class Pair1
{
private:
    T m_b;
    T m_а;
public:
    Pair1(T a, T b) { m_а=a; m_b=b; }
    T first()
    {
        return m_а;
    }
    T second()
    {
        return m_b;
    }
    ~Pair1() {}
};

template<class T, class T1>//
class Pair
{
private:

    T1 m_b;
    T m_а;
public:
    Pair(T a, T1 b) { m_а = a; m_b = b; }
T first()
    {
        return m_а;
    }
    T1 second()
    {
        return m_b;
    }
    ~Pair() {}
};

template<class T>
class StringValuePair : public Pair<string,T>
{
public:
    StringValuePair(string a, T b) { m_а = a; m_b = b; }
        ~StringValuePair();
};

int main()
{
    std::cout << "task 1\n";
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    
    std::cout << "\ntask 2\n";
    Pair<int, double> p11(6, 7.8);
    cout << "Pair: " << p11.first() << ' ' << p11.second() << '\n';
    Pair<double, int> p12(3.4, 5);
    cout << "Pair: " << p12.first() << ' ' << p12.second() << '\n';

    std::cout << "\ntask 3\n";
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}
