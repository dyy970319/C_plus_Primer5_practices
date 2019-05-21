#include <algorithm>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vi = {2,3,4,5};
	fill_n(vi.begin(),vi.size(),0);
	cout<<vi[0]<<endl;
	
	vector<int> vec;
	vec.reserve(10);
	fill_n(vec.begin(),10,0);
	
	vector<int> vec2;list<int> lst;int i;
	while(cin>>i)
		lst.push_back(i);
	copy(lst.cbegin(),lst.cend(),back_inserter(vec2));
	cout<<vec2[0]<<endl;
}