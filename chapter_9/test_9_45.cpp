#include <string>
#include <iostream>

using namespace std;

string add(string &name,string prefix,string suffix)
{
	auto beg = name.begin();
	name.insert(beg,prefix.begin(),prefix.end());
	name.append(suffix);
	return name;
}

int main()
{
	string s = "sfjldh";
	cout<<add(s,"A","B");
}