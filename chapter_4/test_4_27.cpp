#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	unsigned long ul1 = 3,ul2 = 7;
	cout<<(ul1&ul2)<<endl;
	cout<<(ul1|ul2)<<endl;
	cout<<(ul1&&ul2)<<endl;
	cout<<(ul1||ul2)<<endl;
}