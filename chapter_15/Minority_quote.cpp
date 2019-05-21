#include "Minority_quote.hpp"

double Minority_quote::net_price(size_t cnt)const
{
	if(cnt <= quantity)
		return cnt * (1 - discount) * price;
	else{
		return (cnt - quantity)*price + quantity * price * (1 - discount);
	}
}

void Minority_quote::Debug() {
	Quote::Debug();
	cout<<"max_qty:"<<max_qty<<endl;
	cout<<"discount:"<<discount<<endl;
}