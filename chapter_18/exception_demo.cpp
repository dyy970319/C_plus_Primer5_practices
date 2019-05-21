#include <cstdlib>
#include <iostream>

using namespace std;

typedef int EXCPTYPE;

class exceptionType { };

int main()
{
	//try{
	try{
		EXCPTYPE one;
		exceptionType *et;
		throw one;
	}
	catch(EXCPTYPE e){
		cout<<"EXCPTYPE"<<endl;
		throw;
	}
	catch(exceptionType *pt){
		cout<<"exceptionType"<<endl;
		throw;
	}
	/*catch(...){
		cout<<"..."<<endl;
	}*/
	
	/*try{
		range_error r("error");
		throw r;
	}
	catch(exception e){
		cout<<"catch"<<endl;
		//cout<<e<<endl;
		abort();
	}*/
	/*catch(EXCPTYPE e){
		cout<<"test"<<endl;
	}*/
}
