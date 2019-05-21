#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	int sum = 0;
	int val = 0;
	while (val <= 10)
		sum+=val,++val;
	cout<<sum<<endl;
}