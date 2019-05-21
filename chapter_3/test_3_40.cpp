#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	char ca[] = "abc";
	char cb[] = "abd";
	char result[10];
	strcpy(result,ca);
	strcat(result,cb);
	cout<<result<<endl;
}					