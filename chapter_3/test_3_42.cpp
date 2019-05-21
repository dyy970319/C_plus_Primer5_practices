#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	vector<int> ivec(3,1);
	int ia[3];
	int i = 0;
	for(auto it = ivec.begin();it !=ivec.end();it++){
		ia[i] = *it;
		cout<<ia[i]<<endl;
		i++;
	}
}					