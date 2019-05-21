#include "IsEqual.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
	IsEqual ie;
	vector<int> test(3,1);
	int num = 1;
	for_each(test.begin(),test.end(),[num,ie](int &i){
		if(ie(i,num))
			i = 4;
	});
	cout<<test[0]<<endl;
}