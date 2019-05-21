#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input = "kd*h)f*e";
	string result;
	int k = 0;
	for (auto c:input){
		if(!ispunct(c)){
			result += c;
			k++;
			}
	}
	cout<<result<<endl;
}					