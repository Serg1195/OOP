//у меня многое не получалось, оказалось, что в стандарты с++14 стояли по умолчанию в visual studio
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <iosfwd>

using namespace std;

class stdd {
public:
	stdd() {	}
	string endll()
	{
		return "\n\n";

	}
private:
};

int main()
{
	stdd s;
	char x='n';
	//cin >> x;
	cout << boolalpha << (bool)isdigit(x);
		s.endll();//выдаёт 4 или 0 ()
}
