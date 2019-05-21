#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <cassert>

using namespace std;
using std::vector;

int main()
{
	string s;
	string sought = "ab";
	while(cin>>s && s!=sought){}
	assert(cin);
}
	
