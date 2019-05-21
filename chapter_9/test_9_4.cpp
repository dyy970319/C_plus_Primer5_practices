#include <vector>

using namespace std;

bool findYesOrNo(vector<int>::iterator beg,
vector<int>::iterator end,int value){
	while(beg!=end){
		if(*beg == value)
			return true;
		++beg;
	}
	return false;
}

int main()
{
	
}
