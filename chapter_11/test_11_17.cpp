#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	multiset<string> c;
	vector<string> v;
	//copy(v.begin(),v.end(),inserter(c,c.end()));
	//copy(v.begin(),v.end(),back_inserter(c));
	//copy(c.begin(),c.end(),inserter(v,v.end()));
	copy(c.begin(),c.end(),back_inserter(v));
}