#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ifstream in_file("test.txt");
	string central_line_above = "bdhfk";
	string under_central_line = "gjpqy";
	central_line_above += under_central_line;
	string word;
	vector<string> result;
	//string result;
	while(in_file>>word)
	{
		if(word.find_first_of(central_line_above)
			== string::npos){
			if(result.size() == 0){
				result.push_back(word);
				continue;
			}
			if(word.size() > result[0].size()){
				result.clear();
				result.push_back(word);
			}else if(word.size() == result[0].size()){
				result.push_back(word);
			}
		}
	}
	if(result.size() == 0)
		cout<<"未找到符合要求的单词"<<endl;
	else{
		cout<<"最长的单词 ：";
		for(auto beg = result.begin();beg != result.end();++beg)
		{
			cout<<*beg<<" ";
		}
	}
}