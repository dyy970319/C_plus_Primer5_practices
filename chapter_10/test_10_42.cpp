#include <list>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

ostream& coutVec(list<string> &words)
{
	for(auto beg = words.begin();beg != words.end();++beg)
	{
		cout<<*beg<<" ";
	}
	return cout;
}

void elimDups(list<string> &words)
{
	//coutVec(words)<<endl;
	//sort(words.begin(),words.end());
	words.sort();
	//coutVec(words)<<endl;
	words.unique();
	
	//auto end_unique = unique(words.begin(),words.end());
	coutVec(words)<<endl;
	//words.erase(end_unique,words.end());
	//coutVec(words)<<endl;
}



int main()
{
	list<string> vec_str = {"the","quick","handsome","handsome"
		,"beutiful","amazing","amazing"};
	elimDups(vec_str);
}