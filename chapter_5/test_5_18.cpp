#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	/*do {
		int v1,v2;
		cout<<"Please enter two numbers to sum:";
		if(cin>>v1>>v2)
			cout<<"Sum is: "<<v1+v2<<endl;
		}
	while(cin);*/
	/*do{
		int ival = 0;
	}while(ival);*/
	do{
		string t1,t2;
		cout<<"Please enter two strings to compare:";
		if(cin>>t1>>t2){
			auto t1_length = t1.size();
			auto t2_length = t2.size();
			if(t1_length > t2_length)
				cout<<t2<<endl;
			else if (t1_length < t2_length)
				cout<<t1<<endl;
			else
				cout<<"they are isometric"<<endl;
		}
	}while(cin);
}