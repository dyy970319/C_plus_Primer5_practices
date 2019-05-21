#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

struct Person{
	Person():name("deng handsome"),addr("the milky way"){}
	string name;
	string addr;
	string rName() const{return name;}
	string rAddr() const{return addr;}
};

istream &read(istream &is, Person &one){
	is>>one.name>>one.addr;
	return is;
}

ostream &print(ostream &os,const Person &one){
	os<<one.name<<" "<<one.addr;
	return os;
}

int main()
{
	
}
	
