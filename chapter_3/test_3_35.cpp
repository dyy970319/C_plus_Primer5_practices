#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	constexpr size_t sz = 10;
	int ia[sz];
	for(int *p = ia;p != end(ia) ; p++){
		*p = 0;
		cout<<*p<<endl;
		}
}					