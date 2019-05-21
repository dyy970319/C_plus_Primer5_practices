#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vi = {1,2,3};
	for(auto rbeg = vi.crbegin(); rbeg != vi.crend(); ++rbeg)
	{
		cout<<*rbeg<<endl;
	}
}