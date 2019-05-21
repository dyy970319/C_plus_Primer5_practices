#include "Disc_quote.hpp"

class Bulk_quote : public Disc_quote{
	public:
		Bulk_quote() = default;
		Bulk_quote(const string &book,double p,size_t qty,double disc):
			Disc_quote(book,p,qty,disc){
				//cout<<"Bulk_quote(const string &,double,size_t,double)"<<endl;
				}
		//using Disc_quote::Disc_quote;
		double net_price(size_t)const override;
		void Debug() override;
		Bulk_quote(const Bulk_quote&bq):
			Disc_quote(bq){
				//cout<<"Bulk_quote(const Bulk_quote&bq)"<<endl;
				}
		Bulk_quote(Bulk_quote&&bq):
			Disc_quote(std::move(bq)){}
		~Bulk_quote(){
			//cout<<"~Bulk_quote()"<<endl;
		}
		Bulk_quote *clone() const & {return new Bulk_quote(*this);}
		Bulk_quote *clone() && {return new Bulk_quote(std::move(*this));}
};

double Bulk_quote::net_price(size_t cnt)const
{
	if(cnt >= quantity)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}
void Bulk_quote::Debug() {
	Quote::Debug();
	cout<<"min_qty:"<<quantity<<endl;
	cout<<"discount:"<<discount<<endl;
}


