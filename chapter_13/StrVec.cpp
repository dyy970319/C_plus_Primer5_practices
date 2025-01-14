#include "StrVec.h"
#include <algorithm>
#include <numeric>

void StrVec::push_back(const string&s)
{
	chk_n_alloc();
	alloc.construct(first_free++,s);
}

void StrVec::pop_back()
{
	alloc.destroy(--first_free);
}

pair<string*,string*>
StrVec::alloc_n_copy(const string *b,const string *e)
{
	auto data = alloc.allocate(e - b);
	return {data,uninitialized_copy(b,e,data)};
}

void StrVec::free()
{
	if(elements){
		auto p = first_free;
		//for_each(first_free,elements,[&p](string s){alloc.destroy(--p);});
		for(auto p = first_free;p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements,cap - elements);
	}
}

StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(),s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&s)  noexcept
	:elements(s.elements),first_free(s.first_free),cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec::~StrVec(){free();}

StrVec &StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(),rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs)
{
	if(this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size();++i)
		alloc.construct(dest++,move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
	/*auto newcapacity = size() ? 2 *size():1;
	auto first = alloc.allocate(newcapacity);
	auto last = uninitialized_copy(make_move_iterator(begin()),
						make_move_iterator(end()),
						first);
	free();
	elements = first;
	first_free = last;
	cap = elements + newcapacity;*/
}

void StrVec::reserve(int i)
{
	alloc.allocate(i);
}

void StrVec::resize(int i)
{
	if(capacity() < i){
		while(capacity() < i){
			reallocate();
			alloc.construct(first_free++," ");
		}
	}
	else{
		while(capacity() > i)
			alloc.destroy(--first_free);
	}
}

void StrVec::resize(int i,string s)
{
	if(capacity() < i){
		while(capacity() < i){
			reallocate();
			alloc.construct(first_free++,s);
		}
	}
	else{
		while(capacity() > i)
			alloc.destroy(--first_free);
	}
}