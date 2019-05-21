#include <vector>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	vector<char> vc_test = {'a','b',' '};
	//char noNull[] = {'H','i',' '};
	string s1(vc_test.begin(),vc_test.end());
	cout<<s1<<endl;
}
