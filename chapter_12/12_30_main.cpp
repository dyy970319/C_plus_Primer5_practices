//#include "12_30_QueryResult.h"
#include "12_30_TextQuery.h"
//#include "StrBlobPtr.cpp"
#include <algorithm>

StrBlobPtr StrBlob::begin(){
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
	auto ret = StrBlobPtr(*this,data->size());
	return StrBlobPtr(*this);
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i,const string &msg)
const{
	auto ret = wptr.lock();
	if(!ret)
		throw runtime_error("unbound StrBlobPtr");
	if(i >= ret -> size())
		throw out_of_range(msg);
	return ret;
}

string& StrBlobPtr::deref() const
{
	//auto p = check(curr,"dereference past end");
	return (*check(curr,"dereference past end"))[curr];//(*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr,"increment past end of StrBlobPtr");
	++curr;
	return *this;
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
			lines->insert(n);
		}
	}
}

tuple<string,shared_ptr<set<vector<string>::size_type>>,shared_ptr<StrBlob>>  TextQuery::query(const string& sought) const
{
	static shared_ptr<set<vector<string>::size_type>> nodata(new set<vector<string>::size_type>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return make_tuple(sought,nodata,file);
	else
		return make_tuple(sought,loc->second,file);
}

string make_plural(int size,string s1,string s2)
{
	return size == 1 ? s1 : s1+s2;
}

ostream &print(ostream &os , const auto &qr)
{
	os<<get<0>(qr)<<" occurs"<<get<1>(qr) -> size() << " "
	<<make_plural(get<1>(qr)->size(),"time","s")<<endl;
	auto beg = get<2>(qr) -> begin();
	for(auto num : *get<1>(qr)){
		os<<"\t(line "<<num + 1 <<")  "
		<<beg.deref()<<endl;
		beg = beg.incr();
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
	return 0;
}
