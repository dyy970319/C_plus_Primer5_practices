#include <string>
#include <deque>
#include <iostream>

using namespace std;

int main()
{
	string s;
	deque<string> ds_test;
	while(cin>>s)
		ds_test.push_back(s);
	deque<string>::reverse_iterator r_iter1 = ds_test.rbegin();
	deque<string>::reverse_iterator r_iter2 = ds_test.rend();
	while(r_iter1 != r_iter2){
		cout<<*r_iter1<<endl;
		++r_iter1;
	}
}