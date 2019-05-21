#include "QueryResult.h"
#include <algorithm>

StrBlobPtr StrBlob::begin(){
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
	auto ret = StrBlobPtr(*this,data->size());
	return StrBlobPtr(*this);
}

TextQuery::TextQuery(ifstream& is):file(new StrBlob())
{
	string text;
	while(getline(is,text)){
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while(line>>word){
			auto &lines = wm[word];
			if(!lines)
				lines.reset(new set<line_no>);
			//initializer_list<string> test;
			lines->insert(n);
		}
	}
}

TextQuery::QueryResult TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought,nodata,file);
	else
		return QueryResult(sought,loc->second,file);
}

string make_plural(int size,string s1,string s2)
{
	return size == 1 ? s1 : s1+s2;
}

ostream &print(ostream &os , const TextQuery::QueryResult &qr)
{
	os<<qr.sought<<" occurs"<<qr.lines -> size() << " "
	<<make_plural(qr.lines->size(),"time","s")<<endl;
	auto beg = qr.file -> begin();
	int beg_num = 0;
	for(auto num : *qr.lines){
		while(beg_num != num){
			beg = beg.incr();
			beg_num++;
		}
		os<<"\t(line "<<num + 1 <<")  "
		<<beg.deref()<<endl;
		
		//beg = beg.incr();
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
