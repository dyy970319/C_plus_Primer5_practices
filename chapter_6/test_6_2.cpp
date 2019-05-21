#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int fact(int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}

int sub(int val)
{
	if(val<0)
		val = -val;
	return val;
}

int main()
{
	int val1;
	cout<<"请输入一个数字："<<endl;
	cin>>val1;
	cout<<sub(val1)<<endl;
}

int calc(int c1,int c2){}