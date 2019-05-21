#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <memory>
#include <iostream>
#include "StrBlobPtr.h"

using namespace std;

class QueryResult;
class TextQuery{
	public:
		/*QueryResult(string s,TextQuery &t_query);
		//print();
		inline string getElement(){return element;}
		inline int get_times(){return number_times;}
		inline map<int,string> get_map(){return line_and_txt;}*/
		using line_no = vector<string>::size_type;
		TextQuery(ifstream&);
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
	
	private:
		shared_ptr<StrBlob> file;
		map<string,shared_ptr<set<line_no>>> wm;
		/*string element;
		int number_times;
		map<int,string> line_and_txt;*/
};