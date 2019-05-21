#include "StrBlob.h"


StrBlob::StrBlob():data(make_shared<StrVec>()){
	}

StrBlob::StrBlob(initializer_list<string> il):
	data(make_shared<StrVec>(il)){}
		
void StrBlob::check(size_type i,const string &msg) const
{
	if(i >= data->size())
		throw out_of_range(msg);
}

string& StrBlob::front()
{
	//如果vector为空，check会抛出一个异常
	check(0,"front on empty StrBlob");
	return *data -> begin();
}

string& StrBlob::front()const
{
	//如果vector为空，check会抛出一个异常
	check(0,"front on empty StrBlob");
	return *data -> begin();
}

string& StrBlob::back()
{
	//如果vector为空，check会抛出一个异常
	check(0,"back on empty StrBlob");
	return *data -> end();
}

string& StrBlob::back()const
{
	//如果vector为空，check会抛出一个异常
	check(0,"back on empty StrBlob");
	return *data -> end();
}

void StrBlob::pop_back()
{
	check(0,"pop_back on empty StrBlob");
	data -> pop_back();
}
		