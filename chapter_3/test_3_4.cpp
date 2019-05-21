#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1 , str2;
	cin>>str1>>str2;
	if(str1.size() == str2.size())//(str1 == str2)
		cout<<"等长"<<endl;//"相等"<<endl;
	else if(str1 > str2){
		cout<<str1<<endl;
	}else{
		cout<<str2<<endl;
	}
}					