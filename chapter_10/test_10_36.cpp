#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	list<int> li = {1,2,3,0};
	auto last_0_iter = find(li.crbegin(),li.crend(),0);
	
}