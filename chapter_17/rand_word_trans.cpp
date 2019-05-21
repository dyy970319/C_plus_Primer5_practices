#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

map<string,vector<string>> buildMap(ifstream &map_file)
{
	map<string,vector<string>> trans_map;
	string key;
	string value;
	while(map_file >> key && getline(map_file,value)){
		if(value.size() > 1){
			trans_map[key].push_back(value.substr(1));
		}
		else 
			throw runtime_error("no rule for" + key);
	}
	return trans_map;
}
unsigned int random_uns_int(auto seed,auto min_value,auto max_value);

const string & transform(const string &s,const map<string,vector<string>> &m)
{
	auto map_it = m.find(s);
	if(map_it != m.cend()){
		size_t length = (map_it -> second).size();
		unsigned int rand_num = random_uns_int(time(0),1,(map_it -> second).size());
		return (map_it -> second)[rand_num-1];
	}
	else 
		return s;
}

void world_transform(ifstream &map_file,ifstream &input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while(getline(input,text)){
		istringstream stream(text);
		string word;
		bool firstword = true;
		while(stream >> word){
			if(firstword)
				firstword = false;
			else
				cout << " ";
			cout<<transform(word,trans_map);
		}
		cout<<endl;
	}
}

unsigned int random_uns_int(auto seed,auto min_value,auto max_value){
	static default_random_engine e(seed);
	uniform_int_distribution<unsigned> u(min_value,max_value);
	return u(e);
}

int main()
{
	ifstream test1("read.txt");
	ifstream test2("regulation.txt");
	world_transform(test2,test1);
}