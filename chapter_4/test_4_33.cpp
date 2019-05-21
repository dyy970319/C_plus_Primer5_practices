#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	int x =0;
	int y = 1;
	bool someValue = true;
	someValue ?++x,++y:--x,--y;
	cout<<x<<y<<endl;
}