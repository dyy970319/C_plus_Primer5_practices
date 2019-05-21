#include <bitset>
#include <iostream>
#include <regex>

using namespace std;

struct Answer{
	unsigned long long result;
	void updataAnswer(unsigned number,bool correctness){
		result ^= 1ULL << number;
	}
};
int main()
{
	unsigned long long correct_result = 0;
	Answer test;
	auto score = ~(test.result ^ correct_result);//计算出占的个数。
	//cout<<"\vHi!\n\vtest"<<endl;
	try{
		regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$",regex::icase);
	}catch(regex_error e)
	{
		cout<<e.what()<<"\ncode: "<<e.code()<<endl;
	}
	
}