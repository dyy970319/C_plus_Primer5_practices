#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

void sum(initializer_list<int> il){
	/*int sum = 0;
	for(auto beg = il.begin();beg!=il.end();++beg){
		sum += *beg;
	}
	cout<<sum<<endl;*/
	for(const auto elem : il)
		cout<<elem<<endl;
}

int main()
{
	//initializer_list<int> test = {3,4,5};
	//initializer_list<int>  a = {2};
	//initializer_list<int>  b = {4};
	sum({3,4,5,5});
}
