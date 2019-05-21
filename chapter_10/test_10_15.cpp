#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int i1 = 1;
	auto f = [i1](int i2) -> int{
		return i1 + i2;
	};
	cout<<f(2)<<endl;

}