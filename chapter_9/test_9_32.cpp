#include <forward_list>
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
	auto iter = vi.begin();
	while(iter != vi.end()){
		if(*iter % 2){
			iter = vi.insert (iter,*iter++);
			iter++;
		}else
		{
			iter = vi.erase(iter);
		}
	}
	auto test = vi.begin();
	test++;
	cout<<*test;
}