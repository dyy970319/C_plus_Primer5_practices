#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<int> iv(10,1);
	vector<int>::iterator iter = iv.begin(),mid = iv.begin() + iv.size()/2;
	int dis = iv.size()/2;
	int count = 1;
	while(iter != mid){
		if(*iter == 1){
			iter = iv.insert(iter,2*1) + 2;
			mid = iv.begin() + dis + count;
			++count;
			/*++size;
			if(size % 2 == 0)
				++mid;*/
		}else
			++iter;
		//cout<<*iter<<endl;
	}
	cout<<iv.size()<<endl;
	//cout<<iv[0]<<endl;
	for(int i = 0;i<10;i++){
		cout<<iv[i]<<endl;
		}
}