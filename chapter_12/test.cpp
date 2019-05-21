#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main(){
	/*auto sp = make_shared<int>();
	auto p = sp.get();
	delete p;
	cout<<*sp<<endl;
	cout<<*p<<endl;*/
	
	
	//12.24
	string s;
	cin>>s;
	//char cp[0];
	char *cp = new char[s.size()+1];
	for(int i = 0 ;i != s.size();++i)
	{
		cp[i] = s[i];
	}
	cout<<cp[3]<<endl;
	delete [] cp;
}