#include <iostream>
#include <string>

using namespace std;
int main()
{
	int v2 = 0;
	const *p1 = &v2,&r2 = v2;
	r2 = 3;
}