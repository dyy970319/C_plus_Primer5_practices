#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <fstream>

using namespace std;
using std::vector;

struct Sales_data{
	//Sales_data() = default;
	friend istream &read(istream &,Sales_data &);
	friend Sales_data& combine(const Sales_data);
	friend ostream &print(ostream &,const Sales_data &);
	public:
		Sales_data(const string &s,unsigned n ,double p):
			bookNo(s),units_sold(n),revenue(p*n){cout<<"Sales_data(const string &s,unsigned n ,double p)"<<endl;} 
		Sales_data():Sales_data(" ",0,0){ cout<<"Sales_data()"<<endl;}
		//explicit Sales_data(string s):Sales_data(s,0,0){cout<<"Sales_data(string s)"<<endl;}
		Sales_data(const string &s):bookNo(s){cout<<bookNo<<endl;}
		Sales_data(istream &is ):Sales_data(){
			cout<<"Sales_data(istream &is )"<<endl;
			read(is,*this);
		}
		Sales_data& combine(const Sales_data&);
		string isbn() const {return bookNo;}
		istream &read(istream &is,Sales_data &item);
	private:
		inline double avg_price() const
			{return units_sold ? revenue/units_sold : 0;}
		string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
};

istream &read(istream &is,Sales_data &item){
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

Sales_data& Sales_data::combine(const Sales_data& rhs){
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

int main(int argc,char* argv[])
{
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	Sales_data total;
	if(read(input,total)){
		Sales_data trans;
		while(read(input,trans)){
			if(total.isbn() == trans.isbn())
				total.combine(trans);
			else{
				print(output,total)<<endl;
				total = trans;
			}
		}
		print(output,total)<<endl;
	}else{
		cerr<<"No data?!"<<endl;
	}
}
	
