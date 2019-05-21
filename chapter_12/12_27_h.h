#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class TextQuery;
class QueryResult{
	public:
		QueryResult(string s,TextQuery &t_query);
		//print();
		inline string getElement(){return element;}
		inline int get_times(){return number_times;}
		inline map<int,string> get_map(){return line_and_txt;}
	private:
		string element;
		int number_times;
		map<int,string> line_and_txt;
};
class TextQuery{
	friend class QueryResult;
	public:
		TextQuery(ifstream &is);
		shared_ptr<QueryResult> query(string s);
	private:
		vector<string> inputLine;
		map<string,set<int>> connect;
		map<string,int> time_connect;
};

TextQuery::TextQuery(ifstream &is){
	string line;
	int line_number = 0;
	while(getline(is,line)){
		++line_number;
		inputLine.push_back(line);
		istringstream record(line);
		string word;
		while(record>>word){
			time_connect[word]++;
			connect[word].insert(line_number);
		}
	}	
}

QueryResult::QueryResult(string s,TextQuery &t_query){
	cout<<"enter QueryResult"<<endl;
	int test_number = 1;
	number_times = t_query.time_connect[s];
	cout<<test_number++<<endl;
	set<int> line_set = t_query.connect[s];
	cout<<test_number++<<endl;
	auto beg = line_set.begin();
	cout<<test_number++<<endl;
	while(beg != line_set.end()){
		cout<<test_number++<<endl;
		line_and_txt[*beg] = t_query.inputLine[*beg - 1];
		++beg;
		cout<<test_number++<<endl;
	}
	cout<<test_number++<<endl;
	element = s;
	cout<<"end QueryResult"<<endl;
}

shared_ptr<QueryResult> TextQuery::query(string s){
	cout<<"enter query"<<endl;
	QueryResult query_r = QueryResult(s,*this);
	return make_shared<QueryResult>(query_r);
}

