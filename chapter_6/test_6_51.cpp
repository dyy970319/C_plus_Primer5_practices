#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

void f(){cout<<1<<endl;}
void f(int){cout<<2<<endl;}
void f(int , int){cout<<3<<endl;}
void f(double ,double = 3.14){cout<<4<<endl;}

int main()
{
	float i = 3.14;
	cout<<i<<endl;
	//f(2.56,42);
	f(42);
	f(42,0);
	f(2.56,3.14);
}
	
