#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vi = {1,2,3};
	/*for(auto rbeg = vi.crbegin(); rbeg != vi.crend(); ++rbeg)
	{
		cout<<*rbeg<<endl;
	}*/
	for(auto end = vi.cend();end != vi.cbegin(); --end)
	{
		cout<<*(end - 1)<<endl;
	}
}