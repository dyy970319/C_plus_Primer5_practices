#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

struct Person{
	string name;
	string addr;
	string rName() const{return name;}
	string rAddr() const{return addr;}
};

int main()
{
	
}
	
