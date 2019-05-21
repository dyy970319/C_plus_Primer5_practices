#include <string>
#include <iostream>

using namespace std;

string add(string &name,string prefix,string suffix)
{
	int suf = 0;
	name.insert(suf,prefix);
	suf += name.size();
	name.insert(suf,suffix);
	
	
	return name;
}

int main()
{
	string s = "sfjldh";
	cout<<add(s,"A","B");
}