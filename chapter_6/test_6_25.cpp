#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main(int argc,char *argv[2])
{
	string s1 = argv[0];
	string s2 = argv[1];
	string result = s1 + s2;
	cout<<result<<endl;
}
