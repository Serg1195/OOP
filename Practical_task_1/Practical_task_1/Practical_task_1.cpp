#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdint>
//Task 1
class Power
{
        double x=2;
        double a=2;
public:
    void set(double x1, double a1) { x=x1;  a=a1; }
    double calculate() {return pow(x, a);
    }
};

//Task 2
class RGBA
{
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alhpa = 255;
public:
    RGBA()
    {
        std::cout << "Enter m_red: "; 
        std::cin >> m_red;
        std::cout << "Enter m_green: "; 
        std::cin >> m_green;
        std::cout << "Enter m_blue: "; 
        std::cin >> m_blue;
        std::cout << "Enter m_alhpa: "; 
        std::cin >> m_alhpa;
    }
    void print()
    {
        std::cout << "m_red= " << m_red << std::endl;
        std::cout << "m_green= " << m_green << std::endl;
        std::cout << "m_blue= " << m_blue << std::endl;
        std::cout << "m_alhpa= " << m_alhpa << std::endl;
    }
};
//Task 3
class Stack
{
    int* m_arr;
    int m_length=10;

public:    
    Stack(int length=10)
    {
        assert(length > 0);
        length = m_length;
        m_arr = new int[length];
        for (size_t i = 0; i < length; i++)
        {
            m_arr[i] = i * 10;
        }
        
        m_length = length;       
    }

    void reset()
    {
        for (int i = 0; i >= m_length; i++)
            m_arr[i] = 0;
        m_length = 0;
    }
    bool push(int ell)
    {
        if (m_length < 10)
        {
            m_arr[m_length] = ell;
            m_length++;
            return true;
        }
        else return false;
    }
    int pop()
    {
        int a=0;
        if (m_length != 0)
        {
            a = m_arr[m_length];
            m_arr[m_length] = 0;
            m_length--;
        }
        else std::cout << "Array is not ellements";
        return a;
    }
    void print()
    {
        if (m_length != 0)
            for (int i = 0; i < m_length; i++)
                std::cout << m_arr[i] << ' ';
        else std::cout << ' ';
        std::cout << std::endl;

    }
        


    ~Stack()
    {
        delete[] m_arr;
    }
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{
    //Task 1
    std::cout << "Task 1" << std::endl;
    Power pw;
    std::cout << pw.calculate() << std::endl;
    pw.set(2.2, 2.2);
    std::cout << pw.calculate() << std::endl;
    //Task 2
    std::cout << "\n\n" << "Task 2" << std::endl;
    RGBA Color;
    Color.print();
    //Task 3
    std::cout << "\n\n" << "Task 3" << std::endl;
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

}

