#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	vector<int> i{1,3,5,6,7,12};
	for(auto it = i.begin();it!=i.end();++it){
		(*it)%2==1?(*it)*=2:0;
	}
	for(int k = 0;k<5;++k){
		cout<<i[k]<<endl;
		}
}