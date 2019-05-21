#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <sstream>

using namespace std;
using std::vector;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main()
{
	string line,word;
	vector<PersonInfo> people;
	istringstream record;
	while(getline(cin,line)){
		PersonInfo info;
		record.str(line);
		record>>info.name;
		while(record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}
	cout<<people[0].name<<endl;
}
	
