#include "Quote.hpp"

class Disc_quote:public Quote{
	public:
		Disc_quote() = default;
		Disc_quote(const string &book,double p,size_t qty,double disc)
			:Quote(book,p),quantity(qty),discount(disc){
				//cout<<"Disc_quote(const string &book,double p,size_t qty,double disc)"<<endl;
				}
		double net_price(size_t) const = 0;
		Disc_quote(const Disc_quote&bq):
			Quote(bq),quantity(bq.quantity),discount(bq.discount){
				//cout<<"Disc_quote(const Disc_quote&bq)"<<endl;
				}
		Disc_quote(Disc_quote &&bq):
			Quote(std::move(bq)),quantity(std::move(bq.quantity)),
				discount(std::move(bq.discount)){
					//cout<<"Disc_quote(Disc_quote &&bq)"<<endl;
					}
		~Disc_quote(){
			//cout<<"~Disc_quote()"<<endl;
		}
	protected:
		size_t quantity = 0;
		double discount = 0.0;
};