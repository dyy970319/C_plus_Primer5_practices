#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
	multimap<string,vector<string>> families = {
		{"tian",{"xia","kong"}}
		};
	set<int> test = {2,1,3,11,8};
	cout<<*test.begin()<<endl;
	families.insert({"tian",{"di"}});
	//cout<<families["tian"]<<endl;
}