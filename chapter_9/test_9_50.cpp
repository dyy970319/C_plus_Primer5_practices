#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	vector<string> vs_test= {"1.0","3.3"};
	int result = 0;
	for(auto beg = vs_test.begin();beg != vs_test.end();
		++beg)
	{
		//result += stoi(*beg,0,13);
		result += stod(*beg);
	}
	cout<<result<<endl;
	
}