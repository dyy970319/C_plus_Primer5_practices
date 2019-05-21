#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	/*constexpr size_t array_size = 10;
	int ia[array_size];
	int ib[array_size];
	for(size_t ix = 0 ;ix <array_size;ix++){
		ia[ix] = ix;
		ib[ix] = ia[ix];
	}*/
	vector<int> ia(10);
	unsigned num = 0;
	for(auto it = ia.begin();it!=ia.end();it++){
		*it = num;
		cout<<*it<<endl;
		num++;
		}
}					