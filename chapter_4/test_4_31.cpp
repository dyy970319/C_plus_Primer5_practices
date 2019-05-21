#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	vector<int> ivec(5);
	vector<int>::size_type cnt = ivec.size();
	for(vector<int>::size_type ix = 0;
		ix!=ivec.size();ix++,cnt--){
			ivec[ix]=cnt;
			cout<<ivec[ix]<<endl;
		}
	
}