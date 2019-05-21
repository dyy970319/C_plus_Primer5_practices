#include <string>
#include <vector>
#include <algorithm>
#include  <functional>
#include <iostream>

using namespace std;

template<typename T>
void CountIf(vector<T> vs){
	int number = count_if(vs.begin(),vs.end(),mem_fn(&string::empty));
	cout<<number<<endl;
}

template<typename T>
T FindIf(vector<T> vt,T value){
	auto t = find_if(vt.begin(),vt.end(),[value](T &t){
		if(t > value)
			return true;
		else 
			return false;
	});
	return *t;
}

int main(){
	string a = "test";
	vector<string> vs = {"a","","b"};
	int value = 1;
	vector<int> vi = {0,1,2,3};
	CountIf(vs);
	cout<<FindIf(vi,value)<<endl;
	
}