#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	const char ca[] = {'h','e','l','l','o','\0'};
	const char *cp = ca;
	while(*cp){
		cout<<*cp<<endl;
		cp++;
	}
}					