#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

bool has_upper(const string &s){
	for(decltype(s.size()) i = 0;i != s.size();++i){
		if(isupper(s[i]))
			return true;
	}
	return false;
}

void to_lower(string &s){
	for(decltype(s.size()) i = 0;i != s.size();++i){
		s[i] = toupper(s[i]);
	}
	
}

int main()
{
	string s = "Handsome";
	//cout<<has_upper(s)<<endl;
	to_lower(s);
	cout<<s<<endl;
}
