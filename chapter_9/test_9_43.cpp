#include <string>
#include <iostream>

using namespace std;

void replace(string &s,string oldVal,string newVal)
{
	int oldVal_len = oldVal.size();
	auto iter1 = s.begin();
	auto iter2 = iter1 + oldVal_len;
	while((iter1+oldVal_len -1) != s.end())
	{
		string s_val(iter1,iter2);
		if(s_val == oldVal){
			iter1 = s.erase(iter1,iter2);
			iter1 = s.insert(iter1,newVal.begin(),newVal.end());
		}
		++iter1;
		iter2 = iter1 + oldVal_len;
	}
}


int main(){
	string test = "fs";
	replace(test,"f","fs");
	cout<<test<<endl;
}