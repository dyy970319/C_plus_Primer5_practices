#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <set>
#include <unordered_set>

using namespace std;
using std::vector;
//template<class T> class std::hash;

struct Sales_data{
	friend class std::hash<Sales_data>;
	friend istream &read(istream &,Sales_data &);
	friend Sales_data& combine(const Sales_data);
	friend ostream &print(ostream &,const Sales_data &);
	friend istream &operator>>(istream &,Sales_data &);
	friend ostream &operator<<(ostream &,const Sales_data &);
	friend Sales_data operator+(const Sales_data &,const Sales_data &);
	friend bool operator == (const Sales_data &lhs,const Sales_data &rhs);
	public:
		Sales_data(const string &s,unsigned n ,double p):
			bookNo(s),units_sold(n),revenue(p*n){/*cout<<"Sales_data(const string &s,unsigned n ,double p)"<<endl;*/} 
		Sales_data():Sales_data(" ",0,0){/* cout<<"Sales_data()"<<endl;*/}
		//explicit Sales_data(string s):Sales_data(s,0,0){cout<<"Sales_data(string s)"<<endl;}
		Sales_data(const string &s):bookNo(s){}//cout<<bookNo<<endl;}
		Sales_data(istream &is ):Sales_data(){
			cout<<"Sales_data(istream &is )"<<endl;
			read(is,*this);
		}
		Sales_data& combine(const Sales_data&);
		string isbn() const {return bookNo;}
		istream &read(istream &is,Sales_data &item);
		bool operator == (const Sales_data &sd){return sd.isbn() == this -> isbn();}
		//void operator +=(const Sales_data &);
		Sales_data& operator +=(const Sales_data &);
		Sales_data& operator =(string);
		//Sales_data operator +(const Sales_data &sd){this->combine(sd);return *this;}
	private:
		inline double avg_price() const
			{return units_sold ? revenue/units_sold : 0;}
		string bookNo;
		unsigned units_sold = 0;
		double revenue = 0.0;
};

namespace std{
	template<>
	struct hash<Sales_data>
	{
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data& s) const;
	};
	size_t
	hash<Sales_data>::operator()(const Sales_data& s) const
	{
		return hash<string>() (s.bookNo) ^
			hash<unsigned>()(s.units_sold)^
			hash<double>()(s.revenue);
	}
}

