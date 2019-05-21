#include "Disc_quote.h"

class Minority_quote : public Disc_quote{
	public:
		Minority_quote() = default;
		Minority_quote(const string &book,double p,size_t qty,double disc):
			Disc_quote(book,p,qty,disc){}
		double net_price(size_t)const override;
		void Debug() override;
	private:
		size_t max_qty = 0;
		double discount = 0.0;
};
