#include <list>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	list<const char *> lc_test = {"a","an","the"};
	vector<string> vs_test;
	vs_test.assign(lc_test.begin(),lc_test.end());
	cout<<vs_test[0]<<endl;
}