#include <map>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
	map<string,size_t> word_count;
	string ignore_punc = ",.";
	string word;
	while(cin>>word){
		for(unsigned short i = 0;i != word.size() ;++i)
		{
			if(ignore_punc.find(word[i]) != string::npos){
				word = word.erase(i--,1);
			}
			else
				word[i] = tolower(word[i]);
		}
		
		++word_count[word];
	}
	for(const auto &w : word_count)
	{
		cout<<w.first <<" occurs"<<w.second
			<<((w.second > 1) ? " times" : " time") << endl;
	}
}