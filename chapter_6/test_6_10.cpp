#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

/*int exchange(int *ad1,int *ad2){
	int temp = *ad1;
	*ad1 = *ad2;
	*ad2 = temp;
}*/

int exchange(int &ad1,int &ad2){
	int temp = ad1;
	ad1 = ad2;
	ad2 = temp;
}

int main()
{
	int a = 1, b = 2;
	exchange(a,b);
	cout<<a<<b<<endl;
}
