#include <iostream>
#include <ostream>
using namespace std;

bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

class Endll
{
public:
    Endll()
    {

    }
   void operator<< endline(ostream& out);
};
void operator<< endline(ostream& out)
{
    out<<endl<<endl;
}




int main() {
    Endll endll;
    cout << endll  << 'a' << 'A';
    string x;
  cout<<"Enter a number: ";
  cin>>x;
    while (!is_number(x)) {
        cout << "Enter a number: ";
        cin >> x;
        cout<<endl;
    }
        cout<<"Number: "<< x <<endl;
}
