#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <list>

using namespace std;

int main()
{
	vector<string> vec_str = {"the","quick","abcdef","bckfej","wsdhfl","handsome","handsome"
		,"beutiful","amazink","amazing","amazing",};
	list<string> l_str;
	unique_copy(vec_str.begin(),vec_str.end(),back_inserter(l_str));
	for(auto beg = l_str.begin(); beg != l_str.end() ; ++beg)
	{
		cout<<*beg<<endl;
	}
}