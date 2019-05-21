#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

struct Sales_data{
	Sales_data() = default;
	Sales_data(const string &s):bookNo(s){}
	Sales_data(const string &s,unsigned n ,double p):
		bookNo(s),units_sold(n),revenue(p*n){}
	Sales_data(istream &is ){
		read(is,*this);
	}
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	Sales_data& combine(const Sales_data);
	string isbn() const {return bookNo;}
	istream &read(istream &is,Sales_data &item);
};

istream &Sales_data::read(istream &is,Sales_data &item){
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

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

int main()
{
	Sales_data sld1;
	Sales_data sld2 = Sales_data();
	Sales_data sld3 = Sales_data("feng");
	Sales_data sld4 = Sales_data("feng",1,1.0);
	Sales_data sld5 = Sales_data(cin);
	/*Sales_data total;
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
	}*/
}
	
