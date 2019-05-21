#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include <cstring>
using namespace std;


template<typename T>
size_t vec_appear_times(vector<T> &vec_T,T val)
{
	size_t times = 0;
	for(auto beg = vec_T.cbegin();beg != vec_T.cend();++beg )
	{
		if(*beg == val)
			times++;
	}
	return times;
}

template<>
size_t vec_appear_times(vector<const char*> &vec_T,const char* val)
{
	size_t times = 0;
	for(auto beg = vec_T.cbegin();beg != vec_T.cend();++beg )
	{
		if(strcmp(*beg,val) == 0)
			times++;
	}
	return times;
}

int main()
{
	vector<double> a(10,1);
	vector<int> b(10,1);
	vector<string> c(10,"b");
	vector<const char*>d(2,"c");
	//const char* d_1 = "ab";
	cout<<vec_appear_times(a,1.0)<<endl;
	cout<<vec_appear_times(b,1)<<endl;
	cout<<vec_appear_times(c,(string)"a")<<endl;
	cout<<vec_appear_times(d,"a")<<endl;
	return 0;
}