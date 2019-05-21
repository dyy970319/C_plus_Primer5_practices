#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	cin>>input;
	for(char &i:input)
		i = 'X';
	cout<<input<<endl;
	return 0;	
}					