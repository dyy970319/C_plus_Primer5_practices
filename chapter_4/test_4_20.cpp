#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	vector<string> s{"",""};
	vector<string>::iterator iter;
	iter = s.begin();
	//if(!iter->empty())
		//cout<<*iter<<endl;
	cout<<iter++->empty()<<endl;
	int grade = 60;
	string tst = cout<<(grade<60)?"fail":"pass";
	cout<<tst;
}