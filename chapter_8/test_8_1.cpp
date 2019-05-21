#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

istream& read(istream& is){
	int data;
	while(is>>data){
		if(data == EOF)
			break;
		cout<<data;
	}
	cout<<"break"<<endl;
	is.clear();
	return is;
}

int main()
{
	char test;
	read(cin)>>test;
}
	
