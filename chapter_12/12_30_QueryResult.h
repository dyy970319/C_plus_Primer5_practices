#include "12_30_TextQuery.h"

class QueryResult{
	friend ostream& print(ostream&,const QueryResult&);
	public:
		using line_no = vector<string>::size_type;
		QueryResult(string s,
				shared_ptr<set<line_no>> p,
				shared_ptr<StrBlob> f):
			sought(s),lines(p),file(f) { }
		set<line_no>::iterator begin(){
			return lines->begin();
		}
		set<line_no>::iterator end(){
			return lines->end();
		}
		shared_ptr<StrBlob> get_file()
		{
			return file;
		}
		QueryResult(const QueryResult  &qr)
		{
			sought = qr.sought;
			set<line_no> lines_temp = *qr.lines;
			*lines = lines_temp;
			StrBlob file_temp = *qr.file;
			*file = file_temp;
		}
		
	private:
		string sought;
		shared_ptr<set<line_no>> lines;
		shared_ptr<StrBlob> file;
};