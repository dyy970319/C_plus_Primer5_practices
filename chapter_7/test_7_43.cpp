#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

class NoDefault{
	public:
		NoDefault(int i){}
	private:
		int test ;
};
struct A{
	A(int i = 0):my_mem(NoDefault(i)){}
	NoDefault my_mem;
};

A a;

int main()
{
	vector<A> vec(10);
}
	
