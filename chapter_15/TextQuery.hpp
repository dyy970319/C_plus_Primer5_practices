#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <memory>
#include <iostream>
#include "StrBlobPtr.cpp"
#include "DebugDelete.hpp"

using namespace std;

class QueryResult;
class TextQuery{
	public:
		using line_no = vector<string>::size_type;
		TextQuery(ifstream&,size_t,size_t);
		QueryResult query(const string&) const;
		TextQuery(const TextQuery& tq){
			StrBlob sb = *tq.file;
			*file =sb;
			for(auto beg = tq.wm.begin();beg != tq.wm.end();++beg)
			{
				set<line_no> temp = *(beg ->second);
				*wm[beg->first] = temp;
			}
		}

		TextQuery& operator=(const TextQuery& tq){
			StrBlob sb = *tq.file;
			*file =sb;
			for(auto beg = tq.wm.begin();beg != tq.wm.end();++beg)
			{
				set<line_no> temp = *(beg ->second);
				*wm[beg->first] = temp;
			}
			return *this;
		}
		
		void setRange(size_t min,size_t max){
			cout<<"min"<<min<<endl;
			cout<<"max"<<max<<endl;
			minLineNum = min;
			maxLineNum = max;
		}
	
	private:
		size_t minLineNum = 0,maxLineNum;
		shared_ptr<StrBlob> file;
		map<string,shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream& is,size_t min = 0,size_t max = 0):file(new StrBlob(),DebugDelete()),minLineNum(min)
{
	if(max != 0)
		maxLineNum = max;
	string text;
	cout<<"minLineNum:"<<minLineNum<<endl;
	cout<<"maxLineNum:"<<maxLineNum<<endl;
	while(getline(is,text)){
		file->push_back(text);
		int n = file->size() - 1;
		if(minLineNum >= maxLineNum){
			if((n+1) != minLineNum)
			{
				cout<<"mark1"<<endl;
				continue;
			}
		}else{
			if((n+1) < minLineNum || (n+1) > maxLineNum){
				cout<<"mark2"<<endl;
				continue;
			}
		}
		
		istringstream line(text);
		string word;
		while(line>>word){
			auto &lines = wm[word];
			if(!lines)
				lines.reset(new set<line_no>,DebugDelete());
			//initializer_list<string> test;
			lines->insert(n);
		}
	}
}
