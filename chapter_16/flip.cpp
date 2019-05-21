#include <stdio.h>
#include <utility>
#include <iostream>

using namespace std;

void f(int v1,int &v2)
{
	cout<<v1<<" "<<v2<<endl;
}

void g(int &&i,int& j)
{
	cout<<i<<" "<<j<<endl;
}

template<typename  F,typename T1,typename T2>
	void flip(F f,T1 &&t1,T2 &&t2)
	{
		f(std::forward<T2>(t2),std::forward<T1>(t1));
	}
	
int main()
{
	int i = 10;
	//f(42,i);
	flip(g,i,42);
	flip(f,i,42);
	//cout<<i<<endl;
}