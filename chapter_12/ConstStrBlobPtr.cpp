#include "ConstStrBlobPtr.h"
#include <fstream>
#include <iostream>

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i,const string &msg)
const{
	auto ret = wptr.lock();
	if(!ret)
		throw runtime_error("unbound ConstStrBlobPtr");
	if(i >= ret -> size())
		throw out_of_range(msg);
	return ret;
}

string& ConstStrBlobPtr::deref() const
{
	//auto p = check(curr,"dereference past end");
	return (*check(curr,"dereference past end"))[curr];//(*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
	check(curr,"increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}