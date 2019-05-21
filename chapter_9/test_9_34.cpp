#include <forward_list>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> v = {0,1,2};
	auto iter = v.begin();	
	while(iter != v.end()){
		if(*iter % 2)
			iter = v.insert(iter,*iter);
		++iter;
		cout<<*iter<<endl;
	}
	cout<<v[5]<<" "<<v[1]<<endl;
}