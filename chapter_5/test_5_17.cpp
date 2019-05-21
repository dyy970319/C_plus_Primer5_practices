#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	vector<int> v1,v2;
	v1 = {1,3,4,5,6};
	v2 = {1,3,4,5,7,8};
	if(v1.size() > v2.size()){
		for (int i = 0;i < v2.size();++i){
			if(v1[i] != v2[i]){
				cout<<"false"<<endl;
				return false;
				}
		}
	}
	else if(v1.size() <= v2.size()){
		for (int i = 0;i < v1.size();++i){
			if(v1[i] != v2[i]){
				cout<<"false"<<endl;
				return false;
				}
		}
	}
	cout<<"true"<<endl;
	return true;
	
}