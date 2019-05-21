#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

struct Sales_data{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	Sales_data& combine(const Sales_data);
	string isbn() const {return bookNo;}
};

Sales_data& Sales_data::combine(const Sales_data rhs){
	units_sold += rhs.units_sold;
	revenue += rhs.units_sold;
	return *this;
}

//Sales_data add(const Sales_data&,const Sales_data&);
//ostream &print(ostream&,const Sales_data&);
//istream &read(istream&,Sales_data&);

int main()
{
	Sales_data total;
	if(cin>>total.bookNo>>total.units_sold>>total.revenue){
		Sales_data trans;
		while(cin>>trans.bookNo>>trans.units_sold>>trans.revenue){
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else{
				cout<<total.bookNo<<" "<<total.units_sold<<" "<<total.revenue<<endl;
				total = trans;
			}
		}
		cout<<total.bookNo<<" "<<total.units_sold<<" "<<total.revenue<<endl;
	}else{
		cerr<<"No data?!"<<endl;
	}
}
	
