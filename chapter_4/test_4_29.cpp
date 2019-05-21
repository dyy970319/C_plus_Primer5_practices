#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	long long  x[10]; *p = x;
	cout<<sizeof(x)/sizeof(*x)<<endl;
	cout<<sizeof(p)<<endl;
}