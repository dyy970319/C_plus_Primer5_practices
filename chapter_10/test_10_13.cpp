#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

bool more_or_equal_5(string &s)
{
	if(s.size() >= 5)
		return true;
	else
		return false;
}

int main()
{
	vector<string> vec_str = {"the","quick","handsome","handsome"
		,"beutiful","amazing","amazing"};
	auto accord_end = partition(vec_str.begin(),vec_str.end(),more_or_equal_5);
	auto beg = vec_str.begin();
	while(beg != accord_end){
		cout<<*beg<<endl;
		++beg;
	}
}