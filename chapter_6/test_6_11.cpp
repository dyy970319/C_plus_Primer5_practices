#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

void reset(int &i)
{
	i = 0;
}

void fcn(const int i ){}
void fcn(int i){}

int main()
{
	int num = 1;
	reset(num);
	cout<<num<<endl;
}
