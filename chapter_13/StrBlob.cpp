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
	//���vectorΪ�գ�check���׳�һ���쳣
	check(0,"front on empty StrBlob");
	return *data -> begin();
}

string& StrBlob::front()const
{
	//���vectorΪ�գ�check���׳�һ���쳣
	check(0,"front on empty StrBlob");
	return *data -> begin();
}

string& StrBlob::back()
{
	//���vectorΪ�գ�check���׳�һ���쳣
	check(0,"back on empty StrBlob");
	return *data -> end();
}

string& StrBlob::back()const
{
	//���vectorΪ�գ�check���׳�һ���쳣
	check(0,"back on empty StrBlob");
	return *data -> end();
}

void StrBlob::pop_back()
{
	check(0,"pop_back on empty StrBlob");
	data -> pop_back();
}
		