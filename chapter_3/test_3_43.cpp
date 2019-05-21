#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;
using int_array = int[4];

int main()
{
	int ia[3][4];
	//¢Ù
	/*for(int (&i)[4] : ia ){
		for(int k : i){
			cout<< k<<endl;
		}
	} */
	/*for(int i = 0;i!=(end(ia)-begin(ia));i++){
		for(int k = 0;k!=(end(ia[i])-begin(ia[i]));k++){
			cout<<ia[i][k]<<endl;
		}
	}*/
	for(int_array *p = ia; p != end(ia);p++){
		for(int *q = *p;q != end(*p);q++){
			cout<<*q<<endl;
		}
	}
}					