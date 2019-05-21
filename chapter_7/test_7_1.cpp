#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

struct Sales_data{
	string bookNo;
	unsigned units_sold = 0;
	unsigned double revenue = 0.0;
};

int main()
{
	Sales_data total;
	if(cin>>total){
		Sales_data trans;
		while(cin>>trans){
			if (total.bookNo == trans.bookNo)
				total.units_sold += trans.units_sold;
			else{
				cout<<total.bookNo<<" "<<total.units_sold<<
				" "<<total.revenue<<endl;
				total = trans;
			}
		}
		cout<<total.bookNo<<" "<<
		total.units_sold<<" "<<total.revenue<<endl;
	}else{
		cerr<<"No data?!"<<endl;
		return -1;
	}
	return 0;
}
	
