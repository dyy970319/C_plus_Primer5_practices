#include <iostream>

using namespace std;

int main()
{
	//1.9
	int number = 50;
	int result = 0;
	while(number <= 100){
		result = result + number;
		number++;
	}
	cout<<result<<endl;
	
	//1.10
	for(int i = 10 ; i<0 ; i--){
		cout<<i<<endl;
		}
		
	//1.11
	int min,max;
	cout<<"请输入两个整数："<<endl;
	cin>>min>>max;
	for(;min<=max;min++){
		cout<<min<<endl;
		}
	
	
}					