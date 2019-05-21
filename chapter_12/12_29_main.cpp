#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	vector<string> lines;
	map<int,string> num_and_content;
	ifstream infile("input.txt");
	string line;
	do{
		getline(infile,line);
		lines.push_back(line);
	}while(getline(infile,line));
	unsigned short times = 0;
	do{
		cout<<"enter word to look for,or q to quit£º";
		string s;
		if(!(cin >>s) || s == "q")break;
		int number = 1;
		
		for(auto beg = lines.cbegin();beg != lines.cend();++beg)
		{
			istringstream record(*beg);
			string word;
			while(record>>word){
				if(word == s){
					num_and_content[number] = *beg;
					++times;
				}
			}
			++number;
		}
		cout<<s<<" occurs "<<times<<" times"<<endl;
		for(auto beg = num_and_content.cbegin();
			beg != num_and_content.cend();++beg)
		{
			cout<<"\t(line"<<")"<<beg->first<<beg->second<<";"<<endl;
		}
		times = 0;
		num_and_content.erase(num_and_content.begin(),num_and_content.end());
	}while(true);
}
