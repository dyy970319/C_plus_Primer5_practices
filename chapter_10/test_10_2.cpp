#include <algorithm>
#include <list>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	list<string> vi = {"a","ddb","a"};
	cout<<count(vi.begin(),vi.end(),"ddb")<<endl;
}