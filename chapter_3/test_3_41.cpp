#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	int array1[] = {2,4,5};
	vector<int> ivec(begin(array1),end(array1));
}					