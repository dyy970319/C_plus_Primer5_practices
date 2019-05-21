#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	auto f = [](int i1,int i2) -> int{
		return i1 + i2;
	};
	cout<<f(1,2)<<endl;

}