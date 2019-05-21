#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;

void elimDups(vector<string> &words)
{
	//coutVec(words)<<endl;
	sort(words.begin(),words.end());
	//coutVec(words)<<endl;
	auto end_unique = unique(words.begin(),words.end());
	//coutVec(words)<<endl;
	words.erase(end_unique,words.end());
	//coutVec(words)<<endl;
}

string make_plural(size_t ctr, const string &word,
					const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

bool check_size(const string &s,vector<string>::size_type sz)
{
	return s.size() < sz;
}

ostream &print(ostream &os,const string &s,char c)
{
	return os << s << c;
}

void biggies(vector<string> &words,vector<string>::size_type sz)
{
	elimDups(words);
	sort(words.begin(),words.end(),
		bind(check_size,_1,sz));
	
	auto wc = stable_partition(words.begin(),words.end(),
			bind(check_size,_1,sz));
				
	auto count = words.end() - wc;
	/*auto count = count_if(words.begin(),words.end(),
				bind(check_size,_1,sz));*/
	cout<<count<<" " <<make_plural(count,"word","s")
		<<" of length"<<sz<<" or longer" << endl;
	
	for_each(wc,words.end(),
			bind(print,ref(cout),_1,' '));
	cout<<endl;
}


int main()
{
	vector<string> vec_str = {"the","quick","abcdef","bckfej","wsdhfl","handsome","handsome"
		,"beutiful","amazink","amazing","amazing",};
		
	biggies(vec_str,6);
}