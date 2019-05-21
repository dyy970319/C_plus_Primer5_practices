#include "Sales_data.h"
#include <utility>
#include <sstream>
#include <tuple>
#include <map>

istream &operator>>(istream &is,Sales_data &item)
{
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if(is)
		item.revenue = price * item.units_sold;
	else
		item = Sales_data();
	return is;
}

Sales_data& Sales_data::operator =(string isbn)
{
	/*istringstream iss(isbn);
	double price;
	iss>>this->bookNo>>this->units_sold>>price;
	if(iss)
		this->revenue = price * this->units_sold;
	else
		*this = Sales_data();*/
	cout<<"Sales_data& Sales_data::operator =(string isbn)"<<endl;
	double price;
	int index = 0;
	string s1,s2,s3;
	for(int i = 0;i < isbn.size();++i){
		if(isbn[i] == ' '){
			++index;
			continue;
		}
		if(index ==0)
			s1 += isbn[i];
		else if(index == 1)
			s2 += isbn[i];
		else if(index == 2)
			s3 += isbn[i];
	}
	this -> bookNo = s1;
	cout<<"s1:"<<s1<<"s2:"<<s2<<"s3:"<<s3<<endl;
	stringstream ss1(s2) ;
	ss1>>this -> units_sold;
	stringstream ss2(s3);
	ss2>>price;
	this->revenue = price * this->units_sold;
	return *this;
}

ostream &operator<<(ostream &os,const Sales_data &item){
	os<< item.isbn() << " "<<item.units_sold<<" "
	<< item.revenue<<" "<<item.avg_price();
	return os;
}

Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

Sales_data& Sales_data::operator +=(const Sales_data &rhs)
{
	//units_sold += rhs.units_sold;
	//revenue += rhs.revenue;
	*this = *this + rhs;
	return *this;	
}

/*void Sales_data::operator +=(const Sales_data &item){
	this->combine(item);
}*/

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

bool operator == (const Sales_data &lhs,const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() &&
		lhs.units_sold == rhs.units_sold&&
		lhs.revenue == rhs.revenue;
}

typedef tuple<vector<Sales_data>::size_type,vector<Sales_data>::const_iterator,
	vector<Sales_data>::const_iterator> matches;

typedef pair<vector<Sales_data>::size_type,pair<vector<Sales_data>::const_iterator,
	vector<Sales_data>::const_iterator>> matches2;

typedef map<vector<Sales_data>::size_type,multimap<vector<Sales_data>::const_iterator,
	vector<Sales_data>::const_iterator>> matches3;
//typedef multiset;

vector<matches2> findBook(auto files,const string &book)
{
	vector<matches2> ret;
	/*vector<vector<Sales_data>::size_type> ret1;
	vector<vector<Sales_data>::const_iterator> ret2;
	vector<vector<Sales_data>::const_iterator> ret3;*/
	for(auto it = files.cbegin();it != files.cend();++it){
		auto found = std::equal_range(it -> cbegin(),it -> cend(),book,compareIsbn);
		if(found.first != found.second)/*{
			ret.push_back(found.first);
			ret.push_back(found.second);
		}*/
			ret.push_back(make_pair(it - files.cbegin(),make_pair(found.first,found.second)));
	}
	return ret;
}

void reportResults(istream &in,ostream &os,
	const vector<vector<Sales_data>> &files)
{
	string s;
	while(in >> s){
		/*size_t count = 0;
		for(auto it = files.cbegin();it != files.cend();++it)
		{
			auto store = findBook(it,s);
			if(store.empty()){
				cout<<s<<" not found in any stores"<<endl;
				continue;
			}
			os<<"store "<< count <<" sales: "<<accumulate(store[0],store[1],Sales_data())<<endl;
			count ++;
		}*/
		auto trans = findBook(files,s);
			if(trans.empty()){
				cout<<s<<" not found in any stores"<<endl;
				continue;
			}
		
		for(const auto &store : trans)
			os<<"store "<<store.first<<" sales: "<<accumulate(store.second.first,store.second.second,Sales_data())<<endl;
	}
	cout<<"test"<<endl;
}


int main()
{
	
	Sales_data a("1",1,1);
	Sales_data b("b",3,2);
	vector<Sales_data> test;
	vector<Sales_data> test2;
	test.push_back(a);
	test2.push_back(b);
	test.push_back(b);
	vector<vector<Sales_data>> files;
	files.push_back(test);
	files.push_back(test2);
	//auto dyy = findBook(files,"b");
	reportResults(cin,cout,files);
	
	return 0;
}