#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

struct X {
	X (int i, int j ):base(i),rem(base % j){}
	int rem,base;
};

int main()
{
	X(1,1);
}
	
