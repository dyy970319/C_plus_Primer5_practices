#include <string>
#include <iostream>

using namespace std;

class Quote{
	public:
		Quote() = default;
		Quote(const string &book,double sales_price):
			bookNo(book),price(sales_price){
				//cout<<"Quote(const string &book,double sales_price)"<<endl;
				}
		string isbn() const {return bookNo;}
		virtual double net_price(size_t n)const{
			return n*price;}
		virtual ~Quote() = default;
		virtual void Debug();
		Quote(const Quote&q):
			bookNo(q.bookNo),price(q.price){
				//cout<<"Quote(const Quote&q)"<<endl;
				}
		Quote(Quote&& q):
			bookNo(std::move(q.bookNo)),price(std::move(q.price)){
				//cout<<"Quote(Quote&& q)"<<endl;
				}
		virtual Quote* clone() const & {return new Quote(*this);}
		virtual Quote* clone() &&
			{return new Quote(move(*this));}
	private:
		string bookNo;
	protected:
		double price = 0.0;
};

double print_total(ostream &os,
			const Quote &item,size_t n)
{
	double ret = item.net_price(n);
	os<<"ISBN: "<<item.isbn()
		<<" # sold: "<< n <<" total due: "<<ret <<endl;
	return ret;
}

 void Quote::Debug(){
	cout<<"\tbookNo:"<<bookNo<<endl;
	cout<<"\tprice:"<<price<<endl;
 }

