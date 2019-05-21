#include <string>
#include <iostream>

using namespace std;

void replace(string &s,string oldVal,string newVal)
{
	int oldVal_len = oldVal.size();
	int newVal_len = newVal.size();
	int beg = 0;
	while((beg + oldVal_len -1) != s.size())
	{
		string s_val(s,beg,oldVal_len);
		if(s_val == oldVal){
			s.replace(beg,oldVal_len,newVal);
			beg += newVal_len;
		}else{
			++beg;
		}
	}
}


int main(){
	string test = "fs";
	replace(test,"f","fs");
	cout<<test<<endl;
}