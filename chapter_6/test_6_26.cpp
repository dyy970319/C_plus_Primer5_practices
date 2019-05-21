#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main(int argc,char *argv[])
{
	for (size_t i = 1;i < argc;++i){
		cout<<argv[i]<<endl;
	}
}
