#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	vector<unsigned> scores(11,0);
	unsigned grade;
	int x = 0;
	while(cin>>grade){
		if(x==5)
			break;
		x++;
		if(grade <= 100)
			++(*(scores.begin()+(grade/10)));
	}
	for(unsigned i : scores){
		cout<<i<<endl;
		}
}					