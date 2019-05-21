#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	string s = "word";
	string p1 =s+(s[s.size()-1] == 's'?"":"s");
	cout<<p1<<endl;
}