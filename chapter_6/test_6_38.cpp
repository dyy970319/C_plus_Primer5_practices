#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

decltype(odd) &arrPtr(int i){
	return (i %2) ? odd : even;
}

int main()
{
	cout<<arrPtr(5)[1]<<endl;
}
	
