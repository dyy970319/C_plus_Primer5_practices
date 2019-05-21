#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int main()
{
	vector<double> vi = {0.3,1,2,3,4,5};
	double result = accumulate(vi.cbegin(),vi.cend(),0.0);
	cout<<result<<endl;
}
