#include "12_27_h.h"
#include <iostream>

ostream &print(ostream &os,shared_ptr<QueryResult> shPtrQResult)
{
	cout<<"print enter"<<endl;
	os<< (*shPtrQResult).getElement()<<" occurs "<<
	(*shPtrQResult).get_times()<<" times"<<endl;
	auto line_and_txt = (*shPtrQResult).get_map();
	auto map_it = line_and_txt.cbegin();
	while(map_it != line_and_txt.cend()){
		os<<"    (line"<<map_it->first<<")"<<map_it->second<<";"<<endl;
		++map_it;
	}
	return os;
}

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	while(true){
		cout<<"enter word to look for,or q to quit: ";
		string s;
		if(!(cin >>s) || s == "q")break;
		print(cout,tq.query(s))<<endl;
	}
}

int main()
{
	ifstream infile("input.txt");
	runQueries(infile);
}