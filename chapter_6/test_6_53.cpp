#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int clac(char*,char*){}
int clac(char* const,char* const){}

int main()
{
	char a = 'a';
	char b = 'b';
	clac(&a,&b);
}
	
