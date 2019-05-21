#include <forward_list>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> v = {0,1,2};
	auto begin = v.begin(),end = v.end();	
	while(begin != v.end()){
		++begin;
		begin = v.insert(begin,42);
		++begin;
	}
	cout<<v[0]<<" "<<v[1]<<endl;
}