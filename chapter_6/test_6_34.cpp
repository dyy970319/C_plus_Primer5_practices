#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int factorial(int val)
{
	if (val != 0)
		return factorial(val--) * val;
	return 1;
}

int main()
{
	cout<<factorial(10)<<endl;
}
	
