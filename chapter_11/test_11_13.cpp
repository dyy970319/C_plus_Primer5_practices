#include <string>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<pair<string,int>> v_pair;
	string s;
	int i;
	while(cin>>s>>i)
	{
		//pair<string,int> p(s,i);
		//pair<string,int>p = {s,i};
		v_pair.push_back(make_pair(s,i));
	}
}