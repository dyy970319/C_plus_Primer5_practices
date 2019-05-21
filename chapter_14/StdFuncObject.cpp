#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//a 统计大于1024的值有多少个。
	vector<int> vi;
	int count = 0;
	greater<int> gi;
	for_each(vi.begin(),vi.end(),[&count](const int& i){
		if(i > 1024)
			++count;
	});
	
	//b找到第一个不等于pooh的字符串
	vector<string> vs;
	not_equal_to<string> nets;
	string result = *find_if(vs.begin(),vs.end(),[nets](const string s){
		return nets(s,"pooh");
	});
	
	//将所有的值乘以2
	vector<int> vi2;
	for_each(vi2.begin(),vi2.end(),[](int &i){
		multiplies<int> mi;
		i = mi(i,2);
	});
	
	//使用标准库函数对象判断一个给定的int值是否能被int容器中的所有元素整除
	vector<int> vi3;
	const int ci = 3;
	bool right = true;
	for_each(vi3.begin(),vi3.end(),[ci,&right](int &i){
		modulus<int> di;
		if(!di(ci,i))
		if(!di(ci,i))
			right = false;
	});
}