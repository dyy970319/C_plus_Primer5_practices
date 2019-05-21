#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

ostream& coutVec(vector<string> &words)
{
	for(auto beg = words.begin();beg != words.end();++beg)
	{
		cout<<*beg<<" ";
	}
	return cout;
}

void elimDups(vector<string> &words)
{
	coutVec(words)<<endl;
	sort(words.begin(),words.end());
	coutVec(words)<<endl;
	auto end_unique = unique(words.begin(),words.end());
	coutVec(words)<<endl;
	words.erase(end_unique,words.end());
	coutVec(words)<<endl;
}

bool isShorter(const string &s1,const string &s2)
{
	return s1.size() < s2.size();
}


int main()
{
	vector<string> vec_str = {"the","quick","handsome","handsome"
		,"beutiful","amazing","amazing"};
	elimDups(vec_str);
	stable_sort(vec_str.begin(),vec_str.end(),isShorter);
	coutVec(vec_str)<<endl;
}