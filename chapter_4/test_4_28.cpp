#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	bool a;
	char b;
	wchar_t c;
	char16_t d;
	char32_t e;
	short a1;
	int a2;
	long a3;
	long long a4;
	float a5;
	double a6;
	long double a7;
	cout<<"bool:"<<sizeof(a)<<endl;
	cout<<"char:"<<sizeof(b)<<endl;
	cout<<"wchar_t:"<<sizeof(c)<<endl;
	cout<<"char16_t:"<<sizeof(d)<<endl;
	cout<<"char32_t:"<<sizeof(e)<<endl;
	cout<<"short:"<<sizeof(a1)<<endl;
	cout<<"int:"<<sizeof(a2)<<endl;
	cout<<"long:"<<sizeof(a3)<<endl;
	cout<<"long long:"<<sizeof(a4)<<endl;
	cout<<"float:"<<sizeof(a5)<<endl;
	cout<<"double:"<<sizeof(a6)<<endl;
	cout<<"long double:"<<sizeof(a7)<<endl;
}