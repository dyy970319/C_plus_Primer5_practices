#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int &get(int *arry,int index){return arry[index];}

int main()
{
	int ia[10];
	for(int i = 0;i != 10;++i)
		get(ia,i) = i;
	cout<<ia[3]<<endl;
}
	
