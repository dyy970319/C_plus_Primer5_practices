#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	vector<int> object(10,3);
	for(auto it = object.begin();it != object.end();it++){
		*it = 2*(*it);
	}
	for(auto it = object.begin();it != object.end();it++){
		cout<<*it<<endl;
	}
}					