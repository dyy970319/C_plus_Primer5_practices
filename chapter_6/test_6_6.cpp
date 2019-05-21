#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int test(){
	static int val = 0;
	return val++;
}

int main()
{
	cout<<test()<<endl;
	cout<<test()<<endl;
	cout<<test()<<endl;
	cout<<test()<<endl;
}
