#include "String.h"
#include <iostream>
#include <vector>

String::String(const String &s)
{
	cout<<"copy constructor"<<endl;
}

String::String(String &&s)
{
	cout<<"move constructor"<<endl;
}

String &String::operator=(const String &s)
{
	cout<<"copy assignment operators"<<endl;
	return *this;
}

String &String::operator=(String &&s)
{
	cout<<"move assignment operators"<<endl;
	return *this;
}

int main()
{
	String a,b,c,d;
	vector<String> vts;
	vts.push_back(a);
	vts.push_back(b);
	vts.push_back(c);
	vts.push_back(c);
	vts.push_back(c);
}