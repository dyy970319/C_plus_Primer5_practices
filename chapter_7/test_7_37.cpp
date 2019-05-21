#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

struct Sales_data{
	//Sales_data() = default;
	friend istream &read(istream &,Sales_data &);
	friend Sales_data& combine(const Sales_data);
	friend ostream &print(ostream &,const Sales_data &);
	public:
		//Sales_data():bookNo("feng"),units_sold(0),revenue(0){}
		Sales_data(const string s = " "):bookNo(s){}
		Sales_data(const string &s,unsigned n ,double p):
			bookNo(s),units_sold(n),revenue(p*n){}
		Sales_data(istream &is = cin){
			read(is,*this);
		}
		//Sales_data(istream &is = cin);
		Sales_data& combine(const Sales_data);
		string isbn() const {return bookNo;}
		istream &read(istream &is,Sales_data &item);
	private:
		inline double avg_price() const
			{return units_sold ? revenue/units_sold : 0;}
		string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
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
	//Sales_data next;
	//print(cout,next);
	//Sales_data last("9-9");
	//print(cout,last);
}
	
