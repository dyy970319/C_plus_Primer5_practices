#include <iostream>
#include <string>

using namespace std;

int main()
{
	int var = 10;
	auto f = [var]() mutable->bool {
		if(var == 0)
			return true;
		else{
			--var;
			return false;
		}
	};
	while(!f())
		cout<<"false"<<endl;
}