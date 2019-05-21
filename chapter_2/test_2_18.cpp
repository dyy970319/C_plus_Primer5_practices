#include <iostream>
#include <string>

using namespace std;
int main()
{
	int i = 1;
	int j = 2;
	int *test1 = &i;
	int *test2 = &j;
	test1 = test2;
	cout<<*test1<<endl;
	*test1 = 3;
	cout<< *test1 <<endl;
}