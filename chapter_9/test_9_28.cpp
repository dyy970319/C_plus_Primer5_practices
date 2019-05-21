#include <forward_list>
#include <string>
#include <iostream>

using namespace std;

void insert(forward_list<string> &fs,string s1,string s2)
{
	auto prev = fs.before_begin();
	auto curr = fs.begin();
	while(curr != fs.end())
	{
		if(*curr == s1){
			fs.insert_after(curr,s2);
			break;
		}
		else{
			prev = curr;
			++curr;
		}
	}
	if(curr == fs.end())
		fs.insert_after(prev,s2);
}

int main()
{
	forward_list<string> fs_test = {"dhfelk","dklfhle","adb"};
	insert(fs_test,"dlkfh","c");
	auto test = fs_test.begin();
	for (int i =0 ;i < 3;++i)
	{
		++test;
	}
	cout<<*(test)<<endl;
}