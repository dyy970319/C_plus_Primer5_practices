#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s,vector<string>::size_type sz)
{
	return s.size() > sz;
}

int main()
{
	string i_s = "ab";
	auto cs_bind = bind(check_size,_1,i_s.size());
	vector<string> vec_str = {"the","quick","abcdef","bckfej","wsdhfl","handsome","handsome"
		,"beutiful","amazink","amazing","amazing",};
	for(auto beg = vec_str.begin(); beg != vec_str.end(); ++beg)
	{
		if(cs_bind(*beg)){
			cout<<*beg<<endl;
			break;
		}
	}
}