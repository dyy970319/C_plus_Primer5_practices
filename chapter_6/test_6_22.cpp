#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

void exchange(int* &i1,int* &i2){
	auto temp = i1;
	i1 = i2 ;
	i2 = temp;
}


int main()
{
	int m =1,n=2;
	int *i1 = &m;
	int *i2 = &n;
	exchange(i1,i2);
	cout<<*i1<<*i2<<endl;
}
