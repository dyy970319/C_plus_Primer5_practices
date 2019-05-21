#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	vector<string> v;
	vector<string> max_v;
	string s;
	int max_repeat = 1;
	while(cin>>s)
		v.push_back(s);
	auto beg = v.begin();
	int tem_repeat = 1;
	while(beg!=v.end()){
		++beg;
		if(*beg == *(beg-1))
			++tem_repeat;
		else{
			if(tem_repeat > max_repeat){
				max_repeat = tem_repeat;
				max_v.clear();
				max_v.push_back(*beg);
			}else if(tem_repeat == max_repeat
				&& tem_repeat != 1)
				max_v.push_back(*beg);
			tem_repeat = 1;
		}
	}
	if(max_repeat == 1)
		cout<<"No words appear in succession"<<endl;
	else{
		auto beg2 = max_v.begin();
		while(beg2 != max_v.end()){
			if((beg2+1) == max_v.end())
				cout<<*beg2;
			else
				cout<<*beg2<<',';
			++beg2;
		}
		cout<<"appear "<<max_repeat<<" times"<<endl;
	}
}