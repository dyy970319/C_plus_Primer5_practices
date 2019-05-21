#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	int num1,num2;
	while(cin>>num1>>num2){
		try{
			goto num1;
			if (num2 == 0)
				throw runtime_error("divisor is 0");
			cout<<num1/num2<<endl;
			break;
		}catch(runtime_error err){
			cout<<err.what();
			cout<<"\nEnter two new numbers:"<<endl;
		}
	}
	num1:
		cout<<"test"<<endl;
}