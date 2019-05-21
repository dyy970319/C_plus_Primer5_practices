#include "compare.hpp"
#include <iostream>
#include <vector>
#include "find.hpp"
#include <list>
#include <typeinfo>

using namespace std;

template<typename It>
auto fcn3(It beg,It end) -> decltype(*beg + 0)
{
	return *beg;
}

template<typename T>void g(const T& val){
	const int& test = 3;
	cout<<val<<endl;
	cout<<typeid(T).name()<<endl;
	cout<<typeid(test).name()<<endl;
}

int main(){
	int i = 0;const int ci = i;
	g(i*ci);
}