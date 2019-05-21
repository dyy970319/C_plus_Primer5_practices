#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> fi_test = {0,1,2};
	auto prev = fi_test.before_begin();
	auto curr = fi_test.begin();
	while(curr != fi_test.end())
	{
		if(*curr%2 != 0)
			curr = fi_test.erase_after(prev);
		else{
			prev = curr;
			++curr;
		}
	}
}