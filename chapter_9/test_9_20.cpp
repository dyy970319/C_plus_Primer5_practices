#include <list>
#include <deque>

using namespace std;

int main()
{
	list<int> li_test = {1,3,4};
	deque<int> di_test1,di_test2;
	for(auto iter = li_test.begin();iter != li_test.end();++iter){
		if(*iter%2 == 0)
			di_test1.push_back(*iter);
		else
			di_test2.push_back(*iter);
	}
}