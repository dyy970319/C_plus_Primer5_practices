#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;
using std::vector;

struct PersonInfo {
	string name;
	vector<string> phones;
};

bool valid(const smatch& m)
{
	if(m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

int main()
{
	string line,word;
	vector<PersonInfo> people;
	ifstream input("test.txt");
	istringstream record;
	while(getline(input,line)){
		PersonInfo info;
		record.str(line);
		record>>info.name;
		while(record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(phone);
	smatch m;
	for(const auto &entry:people)
	{
		ostringstream formatted,badNums;
		for(const auto &nums : entry.phones){
			if(regex_search(nums,m,r)){
				if(!valid(m)){
					badNums<<" " <<nums;
				}else{
					//formatted<<" " <<format(nums);
				}
			}
			
		}
		if(badNums.str().empty())
			cout<<entry.name<<" "<<formatted.str()<<endl;
		else
			cerr<<"input error: "<<entry.name<<" invalid number(s) "<<badNums.str()<<endl;
	}
	
}
	
