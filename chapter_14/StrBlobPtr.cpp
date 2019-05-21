#include "StrBlobPtr.h"
#include <fstream>
#include <iostream>

shared_ptr<StrVec> StrBlobPtr::check(size_t i,const string &msg)
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
	return (*check(curr,"dereference past end")).returnStr(curr);//(*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr,"increment past end of StrBlobPtr");
	++curr;
	return *this;
}

bool operator==(const StrBlobPtr&sbp1,const StrBlobPtr&sbp2)
{
	return sbp1.wptr.lock() == sbp2.wptr.lock();
}

bool operator!=(const StrBlobPtr&sbp1,const StrBlobPtr&sbp2)
{
	return !(sbp1 == sbp2);
}

bool operator <(const StrBlobPtr&sbp1,const StrBlobPtr&sbp2)
{
	return  sbp1.wptr.lock() < sbp2.wptr.lock();
}

bool operator >(const StrBlobPtr&sbp1,const StrBlobPtr&sbp2)
{
	return !(sbp1 == sbp2 || sbp1 < sbp2);
}


StrBlobPtr& StrBlobPtr::operator++(){
	check(curr,"increment past end of StrBlobPtr");
	++curr;
	return *this;
}	
StrBlobPtr& StrBlobPtr::operator--(){
	--curr;
	check(curr,"decrement past begin of StrBlobPtr");
	return *this;
}
StrBlobPtr StrBlobPtr::operator++(int){
	StrBlobPtr ret = *this;
	++*this;
	return ret;
}	
StrBlobPtr StrBlobPtr::operator--(int){
	StrBlobPtr ret = *this;
	--*this;
	return ret;
}
StrBlobPtr& operator+(StrBlobPtr&sbp,size_t i){
	sbp.curr += i;
	sbp.check(sbp.curr,"increment past end of StrBlobPtr");
	return sbp;
}

StrBlobPtr& operator-(StrBlobPtr&sbp,size_t i){
	sbp.curr -= i;
	sbp.check(sbp.curr,"increment past end of StrBlobPtr");
	return sbp;
}

int main()
{
	StrBlob test({"a","b"});
	StrBlobPtr test1(test);
	StrBlobPtr test2 = test1;
	cout<<test2->front()<<endl;
}