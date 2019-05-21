#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;
using std::vector;

struct Sales_data{
	//Sales_data() = default;
	friend istream &read(istream &,Sales_data &);
	friend Sales_data& combine(const Sales_data);
	friend ostream &print(ostream &,const Sales_data &);
	public:
		Sales_data(const string &s,unsigned n ,double p):
			bookNo(s),units_sold(n),revenue(p*n){/*cout<<"Sales_data(const string &s,unsigned n ,double p)"<<endl;*/} 
		Sales_data():Sales_data(" ",0,0){/* cout<<"Sales_data()"<<endl;*/}
		//explicit Sales_data(string s):Sales_data(s,0,0){cout<<"Sales_data(string s)"<<endl;}
		Sales_data(const string &s):bookNo(s){cout<<bookNo<<endl;}
		Sales_data(istream &is ):Sales_data(){
			cout<<"Sales_data(istream &is )"<<endl;
			read(is,*this);
		}
		Sales_data& combine(const Sales_data&);
		string isbn() const {return bookNo;}
		istream &read(istream &is,Sales_data &item);
		bool operator == (const Sales_data &sd){return sd.isbn() == this -> isbn();}
		Sales_data operator +(const Sales_data &sd){this->combine(sd);return *this;}
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
	revenue += rhs.revenue;
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
bool compareIsbn(const Sales_data &sd1,const Sales_data &sd2)
{
	return sd1.isbn() < sd2.isbn();
}

int main()
{
	//istream_iterator<Sales_data> item_iter(cin),eof;
	//ostream_iterater<Sales_data> out_iter(cout,"\n");
	//vector<Sales_data> sales_vec;
	/*while(item_iter != eof){
		sales_vec.push_back(cin);
	}*/
	//sort(sales_vec.begin(),sales_vec_end(),compareIsbn);
	//auto first_data = sales_vec.begin();
	//auto last_data = sales_vec.begin();
	//Sales_data sum;
	/*while(last_data != sales_vec.end()){
		string bookNo = (*first_data).isbn();
		bool hasFind = true;/*find(last_data+1,sales_vec.cend(),[](Sales_data &sd)
		{return sd.isbn() == bookNo;});
		if(hasFind){
			++last_data;
		}else{
			//sum = accumulate(first_data,last_data,add);
			//print(cout,sum);
			first_data = last_data + 1;
			++last_data;
		}
	}*/
	
	vector<Sales_data> vec_sales;
	Sales_data temp;
	while(read(cin,temp)){
		vec_sales.push_back(temp);
	}
	sort(vec_sales.begin(),vec_sales.end(),compareIsbn);
	
	Sales_data sum;
	auto first_iter = vec_sales.begin();
	auto last_iter = vec_sales.begin();
	auto back_iter = vec_sales.end();
	while(last_iter != back_iter)
	{
		//string bookNo = (*first_iter).isbn();
		auto result = find(last_iter + 1,back_iter,*first_iter);
		if(result == back_iter){
			//sum = *first_iter;
			Sales_data temp = Sales_data((*first_iter).isbn(),0,0);
			sum = accumulate(first_iter,last_iter+1,temp);
			print(cout,sum)<<endl;
			first_iter = last_iter + 1;
			++last_iter;
		}else{
			++last_iter;
		}
	}
	
	
}
	
