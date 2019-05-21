#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

//typedef string (&arrS)[10];

//using arrS = string (&)[10];

/*string (&func(string (*s)[10]))[10]{
	return *s;
}

auto func(string (*s)[10]) -> string (&)[10]{
	return *s;
}*/

string test[10];

decltype(test) &func(string (*s)[10]){
	return *s;
}

int main()
{
	string s[10] = {"dhfhe"};
	string s2[10] = func(&s);
	cout<<s2[0]<<endl;
}
	
