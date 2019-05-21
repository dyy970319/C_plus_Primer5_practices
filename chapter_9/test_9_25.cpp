#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> test_vi = {1,2};
	cout<<*(test_vi.erase(test_vi.end(),test_vi.end()));
	//test_vi.clear();
	//test_vi.erase(test_vi.begin());
	//cout<<test_vi[0]<<endl;
	//test_vi.clear();
	cout<<test_vi.at(0)<<endl;
	cout<<test_vi.size()<<endl;
	
}