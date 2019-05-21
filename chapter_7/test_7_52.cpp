#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

struct Sales_data{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0;
};

int main()
{
	Sales_data item = {"9-",25,15.99};
}
	
