#include <iostream>
#include <string>

using namespace std;
std::string global_str;
int global_int;
int main()
{
	int local_int;
	int test_int;
	std::string local_str;
	cout<<global_str<<endl;
	cout<<global_int<<endl;
	cout<<local_int<<endl;
	cout<<local_str<<endl;
	cout<<test_int<<endl;
}