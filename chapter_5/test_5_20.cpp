#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	string last_one,this_one; 
	bool consecutive = false;
	while(cin>>this_one){
		if(!isupper(this_one[0]))
			continue;
		if (this_one == last_one){
			cout<<this_one<<endl;
			consecutive = true;
			break;
		}
		last_one = this_one;
	}
	if (!consecutive)
		cout<<"no words consecutive"<<endl;
}