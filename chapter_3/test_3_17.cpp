#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	vector<string> input(4);
	for(int i = 0;i < 4;i++){
		cin>>input[i];
		for(auto &k:input[i]){
			k = toupper(k);
		}
	}	
	for(auto i:input){
		cout<<i<<endl;
		}
}					