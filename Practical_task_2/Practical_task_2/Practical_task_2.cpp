#include <iostream>
using namespace std;
//Task1
class Person
{
	string m_name;
	int m_age;
	enum Sex { Male, Female, Undefined };
	Sex m_sex;
	int m_weight;
//protected:

public:
	static int count;
	Person() {
		m_name = " ";
		m_age = 0;
		m_weight = 50;
		m_sex = Undefined;
	}
	void setName(string name = "") { m_name = name; }
	void setAge(int age = 20) { m_age = age; }
	void setSex(Sex sex = Undefined) { m_sex = sex; }
	void setWeight(int weight = 50) { m_weight = weight; }
	string getName() const { return m_name; }
	int getAge() const { return m_age; }
	int getWeight() const { return m_weight; }
	Sex getSex() const { return m_sex; }


	~Person() {
		--count;
		m_name = "";
		m_age = 0;
		m_weight = 0;
		m_sex = Undefined;
	};
};

class Student : public Person
{
	int m_YearOfStudy;
public:
	Student() {
		m_YearOfStudy = 0; count++;
	}
	void setYearOfStudy(int YearOfStudy = 0) { m_YearOfStudy = YearOfStudy; }
	void increaseYOS() { m_YearOfStudy++; }
	int getCount() const { return count; }
	void getStudent() const { cout << "Name - " << getName() << "; Age - " << getAge() << "; Sex - " << getSex() << "; Weight - " << getWeight() << "; Year Of Study - " << m_YearOfStudy << endl; }

	
	~Student() { m_YearOfStudy = 0; count--; };
};

int Person::count = 0;

//Task2

class Fruit
{
	string m_name;
	string m_color;
public:
	Fruit(){}
	void setName(string name) { m_name = name; }
	void setColor(string color) { m_color = color; }
	string getName() { return m_name; }
	string getColor() { return m_color; }

	~Fruit() {}
};

class Apple : public Fruit
{
public:
	Apple(string color = "green", string name = "apple") {
		setName(name);
		setColor(color);
	}
};

class Banana : public Fruit
{
public:
	Banana(string color = "yelow", string name = "banana") {
		setName(name);
		setColor(color);
	}
};

class Grannysmith : public Apple
{
public:
	Grannysmith(string color = "green", string name = "granny smith") {
		setName(name);
		setColor(color);
	}
};

int main()
{
	//Task2
	Apple a("red");
	Banana b;
	Grannysmith c;

	cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	cout << "My " << c.getName() << " is " << c.getColor() << ".\n";



	//Task1
	Student Ivanov;
	Ivanov.setName("Ivan");
	Student Petrov;
	Petrov.setName("Petr");
	Student Sidorov;
	Sidorov.setName("Petr");
	Sidorov.getStudent();
	cout << Petrov.getCount();
}