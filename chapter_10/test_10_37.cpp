#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vi = {1,2,3,4,5,6,7,8,9,10};
	list<int> li ;
	auto rbeg = vi.crbegin() + 3;
	auto rend = vi.crend() - 3;
	copy(rbeg,rend,back_inserter(li));
	cout<<*li.begin()<<endl;
}