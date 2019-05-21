#include <vector>
#include <iostream>

using namespace std;

vector<int>::iterator findYesOrNo(vector<int>::iterator beg,
vector<int>::iterator end,int value){
	while(beg!=end){
		if(*beg == value)
			return beg;
		++beg;
	}
	cout<<"Î´ÕÒµ½"<<endl;
	vector<int>::iterator nil;
	return nil;
}

int main()
{
	
}
