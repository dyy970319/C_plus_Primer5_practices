#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//a ͳ�ƴ���1024��ֵ�ж��ٸ���
	vector<int> vi;
	int count = 0;
	greater<int> gi;
	for_each(vi.begin(),vi.end(),[&count](const int& i){
		if(i > 1024)
			++count;
	});
	
	//b�ҵ���һ��������pooh���ַ���
	vector<string> vs;
	not_equal_to<string> nets;
	string result = *find_if(vs.begin(),vs.end(),[nets](const string s){
		return nets(s,"pooh");
	});
	
	//�����е�ֵ����2
	vector<int> vi2;
	for_each(vi2.begin(),vi2.end(),[](int &i){
		multiplies<int> mi;
		i = mi(i,2);
	});
	
	//ʹ�ñ�׼�⺯�������ж�һ��������intֵ�Ƿ��ܱ�int�����е�����Ԫ������
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