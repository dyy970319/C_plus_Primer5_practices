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

Sales_data add(const Sales_data &lhs,const Sales_data &rhs){
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}
ostream &print(ostream &os,const Sales_data &item){
	os << item.isbn() << " "<<item.units_sold<<" "
	<< item.revenue;//<<" "<<item.avg_price();
	return os;
}
istream &read(istream &is,Sales_data &item){
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

int main()
{
	Sales_data total;
	if(read(cin,total)){
		Sales_data trans;
		while(read(cin,total)){
			if(total.isbn() == trans.isbn())
				//add(total,trans);
			else{
				print(cout,total);
				total = trans;
			}
		}
		print(cout,total);
	}else{
		cerr<<"No data?!"<<endl;
	}
}
	
