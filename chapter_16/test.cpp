#include <iostream>
//#include "template_print.hpp"
#include "errorMsg.hpp"

using namespace std;

template<typename T> void f(T t){
	cout<<"f(T)"<<endl;
}
template<typename T> void f(const T*t){
	cout<<"f(const T*)"<<endl;
}
template<typename T> void g(T t){
	cout<<"g(T)"<<endl;
}
template<typename T> void g(T*t){
	cout<<"g(T*)"<<endl;
}

template<typename T,typename... Args>
void foo(const T&t,const Args& ... rest)
{
	cout<<sizeof...(Args)<<endl;
	cout<<sizeof...(rest)<<endl;
}

class test{
	
};

int main(){
	/*int i = 0;double d = 3.14;string s = "how now brown cow";
	test t1;
	print(cout,d,s);*/
	errorMsg(cerr,"a","b");
	//foo(i,s,42,d);
	
}