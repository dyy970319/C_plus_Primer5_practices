#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <sstream>

using namespace std;
using std::vector;

istream& read(istream& is){
	string data;
	while(is>>data){
		//if(data == EOF)
			//break;
		cout<<data;
	}
	cout<<"break"<<endl;
	is.clear();
	return is;
}

int main()
{
	istringstream test("dklfhelh");
	read(test);
}
	
