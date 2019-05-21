#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	const char ca1[] = "abc";
	const char ca2[] = "abc";
	vector<const char*> roster1 = {ca1};
	vector<const char*> roster2 = {ca2};
	cout<<equal(roster1.cbegin(),roster1.cend(),roster2.cbegin())<<endl;
}