#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	vector<int> input(5);
	for(auto &i:input){
		cin>>i;
	}
	/*for(int i = 0;i < (input.size()-1);i++){
		cout<<input[i]+input[i+1]<<endl;
	}*/
	int middle_num = input.size()/2;
	for(int i =0;i<middle_num;i++){
		auto length = input.size();
		cout<<input[i]+input[length-i-1]<<endl;
	}
}					