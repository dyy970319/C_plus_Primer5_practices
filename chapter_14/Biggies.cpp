#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

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

class ShorterString{
	public:
		bool operator()(const string &s1,const string &s2){
			return s1.size()<s2.size();
		}
};

class SizeComp{
	public:
		SizeComp(size_t st):
			sz(st){}
		bool operator()(const string &s)const
		{
			return s.size() >= sz; 
		}
	private:
		size_t sz;
};

class PrintString{
	public:
		PrintString(ostream &o = cout,char c = ' '):
			os(o),sep(c){
				
			}
		void operator()(const string &s){
			os <<s <<sep;
		}
	private:
		ostream &os;
		char sep;
};

void biggies(vector<string> &words,vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(),words.end(),ShorterString()/*
		[](const string &a,const string &b)
			{return a.size() < b.size();}*/);
	auto wc = find_if(words.begin(),words.end(),SizeComp(sz)
			/*[sz](const string &a)
				{return a.size() >= sz;}*/);
				
	auto count = words.end() - wc;
	cout<<count<<" " <<make_plural(count,"word","s")
		<<" of length"<<sz<<" or longer" << endl;
	
	for_each(wc,words.end(),PrintString());
	cout<<endl;
}


int main()
{
	vector<string> vec_str = {"the","quick","handsome","handsome"
		,"beutiful","amazing","amazing"};
		
	biggies(vec_str,6);
}