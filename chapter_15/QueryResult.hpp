#include "TextQuery.hpp"


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

QueryResult TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought,nodata,file);
	else
		return QueryResult(sought,loc->second,file);
}

StrBlobPtr StrBlob::begin(){
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
	auto ret = StrBlobPtr(*this,data->size());
	return StrBlobPtr(*this);
}

string make_plural(int size,string s1,string s2)
{
	return size == 1 ? s1 : s1+s2;
}

ostream &print(ostream &os , const QueryResult &qr)
{
	os<<qr.sought<<" occurs "<<qr.lines -> size() << " "
	<<make_plural(qr.lines->size(),"time","s")<<endl;
	auto beg = qr.file -> begin();
	size_t beg_num = 0;
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