#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	map<string,size_t> word_count;
	string word;
	while(cin>>word){
		auto iter = word_count.insert({word,1});//++word_count[word];
		if(!iter.second)
			++iter.first->second;
	}
	for(const auto &w : word_count)
	{
		cout<<w.first <<" occurs"<<w.second
			<<((w.second > 1) ? " times" : " time") << endl;
	}
}