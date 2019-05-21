#include "String.h"
#include <iostream>
#include <vector>

void String::push_back(const char c)
{
	chk_n_alloc();
	alloc.construct(first_free++,c);
}

pair<char*,char*>String::alloc_n_copy(const char*b,const char*e)
{
	auto data = alloc.allocate(e - b);
	return {data,uninitialized_copy(b,e,data)};
}

String::String(const String &s)
{
	auto newdata = alloc_n_copy(s.begin(),s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
	cout<<"copy constructor"<<endl;
}

String::String(String &&s) noexcept
	:elements(s.elements),first_free(s.first_free),cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
	cout<<"move constructor"<<endl;
}

bool operator == (const String&s1,const String&s2)
{
	return s1.elements == s2.elements &&
		  s1.first_free == s2.first_free &&
		  s1.cap == s2.cap;
}

bool operator != (const String&s1,const String&s2)
{
	cout<<"unequal operator"<<endl;
	return !(s1 == s2);
}


bool operator < (const String&s1,const String&s2)
{
	if(s1.size() < s2.size())
		return true;
	else if(s1.size() > s2.size())
		return false;
	else{
		auto beg1 = s1.elements;
		auto beg2 = s2.elements;
		while(beg1 != s1.first_free)
		{
			if(*beg1 < *beg2)
				return true;
			else if(*beg1 > *beg2)
				return false;
			else{
				++beg1;
				++beg2;
			}
		}
		return false;
	}
	cout<<"less operator"<<endl;
	return true;
}

bool operator > (const String&s1,const String&s2)
{
	cout<<"more operator"<<endl;
	return !(s1 == s2 || s1 < s2);
}

String &String::operator=(const String &s)
{
	elements = s.elements;
	first_free = cap = s.first_free;
	return *this;
}

String &String::operator=(String &&rhs)
{
	cout<<"move assignment operators"<<endl;
	if(this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;	
}

ostream &operator<<(ostream &os,const String&s)
{
	cout<<"output operator"<<endl;
	auto beg = s.elements;
	for(int i = 0; i != s.size();++i)
	{
		cout<<*beg;
		++beg;
	}
}

void String::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size();++i)
		alloc.construct(dest++,*elem++);
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void String::free()
{
	if(elements){
		auto p = first_free;
		for(auto p = first_free;p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements,cap - elements);
	}
}

int main()
{
	String a,b,c,d;
	vector<String> vts;
	vts.push_back(a);
	vts.push_back(b);
	//vts.push_back(c);
	//vts.push_back(c);
	//vts.push_back(c);
}