#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

class EqualThread{
	public:
		bool operator()(const string &s,const size_t i) {
			if(s.length() == i)
				return true;
			else
				return false;
		}
};

int main()
{
	ifstream ifs("input.txt");
	EqualThread et;
	//map<int,int> info;
	/*for(int i = 1;i != 11;++i){
		info[i] = 0;
	}*/
	map<string,int> info;
	info["less_10"] = 0;
	info["more_10"] = 0;
	string line;
	while(getline(ifs,line)){
		istringstream iss(line);
		string word;
		while(iss>>word){
			for(int i = 1;i != 10;++i)
			{
				if(et(word,i)){
					++info["less_10"];
					break;
				}
			}
			if(word.length() > 10)
				++info["more_10"];
		}
	}
	/*for(int i = 1;i != 11;++i){
		cout<<"word's length = "<<i<<":"<<info[i]<<endl;
	}*/
	cout<<"word's length less 10 number:"<<info["less_10"]<<endl;
	cout<<"word's length more 10 number:"<<info["more_10"]<<endl;
}