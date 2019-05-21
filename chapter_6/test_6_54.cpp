#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

//int (*test)(int,int);
/*
int add(int i1,int i2){
	return i1+i2;
}

int sub(int,int);
int (*multi)(int,int);
int (*devide)(int,int);
*/
int add(int a,int b){
	return a+b;
}
int sub(int a,int b){
	return a-b;
}
int multi(int a,int b){
	return a*b;
}
int devide(int a,int b){
	return a/b;
}

int main()
{
	vector<int (*)(int,int)> a{add,sub,multi,devide};
	cout<<a[0](1,3)<<endl;
	cout<<a[1](1,3)<<endl;
	cout<<a[2](1,3)<<endl;
	cout<<a[3](1,3)<<endl;
}
	
