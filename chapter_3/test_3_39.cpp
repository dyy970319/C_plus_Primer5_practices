#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	/*string sa = "abc";
	string sb = "abd";
	if(sa > sb)
		cout<<"sa bigger"<<endl;
	else if(sa == sb)
		cout<<"equal"<<endl;
	else
		cout<<"sa smaller"<<endl;
	return 0;*/
	char ca[] = "abc";
	char cb[] = "abd";
	int result = strcmp(ca,cb);
	if(result>0)
		cout<<"ca bigger"<<endl;
	else if(result == 0)
		cout<<"equal"<<endl;
	else
		cout<<"ca smaller"<<endl;
}					