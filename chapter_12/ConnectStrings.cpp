#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	/*const char c1[] = "ab";
	const char c2[] = "cd";
	char *cp = new char[10];
	int index = 0;
	//cout<<c1[0]<<endl;
	//strcat(c1,c2);
	auto l1 = end(c1) - begin(c1) - 1;
	auto l2 = end(c2) - begin(c2) - 1;
	for(int i = 0;i < l1;++i)
	{
		cp[index] = c1[i];
		cp[index + l1] = c2[i];
		++index;
	}
	cout<<cp[3]<<endl;*/
	string s1 = "ab";
	string s2 = "cd";
	string s = s1 + s2;
	char *cp = new char[s.size()+1];
	for(int i = 0;i < s.size();++i)
	{
		cp[i] = s[i];
		cout<<cp[i]<<endl;
	}
	
}