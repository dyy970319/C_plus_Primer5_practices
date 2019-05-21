#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <list>

using namespace std;

int main()
{
	list<int> vi1 = {1,2,3,4,5,6,7,8,9};
	list<int> vi2,vi3,vi4;
	copy(vi1.cbegin(),vi1.cend(),front_inserter(vi2));
	copy(vi1.cbegin(),vi1.cend(),back_inserter(vi3));
	copy(vi1.cbegin(),vi1.cend(),inserter(vi4,vi4.begin()));
	for(auto beg = vi2.begin(); beg != vi2.end(); ++beg)
	{
		cout<<*beg<<endl;
	}
	for(auto beg = vi3.begin(); beg != vi3.end(); ++beg)
	{
		cout<<*beg<<endl;
	}
	for(auto beg = vi4.begin(); beg != vi4.end(); ++beg)
	{
		cout<<*beg<<endl;
	}
}