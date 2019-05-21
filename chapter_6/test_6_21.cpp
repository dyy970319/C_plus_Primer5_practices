#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int compare(int i1,int *i2){
	if(i1 > *i2)
		return i1;
	else if (i1 < *i2)
		return *i2;
	else
		cout<<"equal"<<endl;
}


int main()
{
	int i1 = 0,i2 = 2;
	cout<<compare(i1,&i2)<<endl;
}
