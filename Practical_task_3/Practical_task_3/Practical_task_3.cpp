#include <iostream>
using namespace std;
//Task 1
class Figure
{
	
public:
	double a;
	double b;
	double S;
	Figure(double width, double length) : a(width), b(length) {}
	Figure(double radius) : a(radius){}
	~Figure();
	virtual double area() = 0;


};

class Parallelogram : public Figure
{
public:
	Parallelogram(double width, double length) : Figure(width, length) {}
	~Parallelogram();
	virtual double area() = 0;
private:

};

class Circle : public Figure
{
public:
	Circle(double radius) : Figure(radius) {};
	double area() {
		S = 3.1415926535*a*a;
		return S;
	}
	~Circle();

private:

};

class Rectangle : public Parallelogram
{

public:
	Rectangle(double width, double length) : Parallelogram(width, length) {}
	double area() {
		S = a * b;
		return S;
	}
		
	~Rectangle();

};

class Square : public Parallelogram
{
public:
	Square(double width) : Parallelogram(width, width) {}
	double area() {
		S = a * a;
		return S;
	}
	~Square();

private:

};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double width, double height) : Parallelogram(width, height) {}
	double area() {
		S = a * b;
		return S;
	}
	~Rhombus();

private:

};

double area(Figure* figure)
{
	return figure->area();
}

//Task 2

class Car
{
public:
	string company;
	string model;
	string type;
	Car() {cout << type << " " << company << " " << model << "!" << endl; }
	
		
	
};

class PassengerCar : virtual public Car
{
	string c="Lada";
	string m="Kalina";
	string t = type;
public:

	PassengerCar() {
		t = "PassengerCar";
		company = c;
		model = m;
	}
//	string setModel()... string setCompany()...
};
class Bus : public Car
{
	string c = "PAZ";
	string m = "3205";
	string t = type;
public:
	Bus() {
		t = "Bus";
		company = c;
		model = m;
	}
	//	string setModel()... string setCompany()...
};
class Minivan : public Bus, public PassengerCar
{
	string c = "VAZ";
	string m = "2120";
public:
	Minivan() {
		Car::type = "Minivan";
		Car::company = c;
		Car::model = m;
		//	string setModel()... string setCompany()...
	}
};

//Task 3
class Fraction
{
	int numerator; int denominator;
public:
	Fraction(int num, int den) :numerator(num), denominator(den) {}
	
};


int main()
{
	Minivan m;
	Bus b;
	
	/*Rectangle* r = new Rectangle(3, 4);
	cout << area(r);
	Square* s = new Square(3);
	cout << area(s);
	Rhombus* rh = new Rhombus(3, 8);
	cout << area(rh);
	Circle* c = new Circle(33);
	cout << area(c);*/

}