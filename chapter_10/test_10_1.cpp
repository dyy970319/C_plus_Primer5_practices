#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vi = {1,2,3,2,4,5,6};
	cout<<count(vi.begin(),vi.end(),2)<<endl;
}