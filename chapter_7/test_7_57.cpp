#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

class Account{
	public:
		void calculate(){amount += amount * interestRate;}
		static double rate() {return interestRate;}
		static void rate(double);
	private:
		string owner;
		double amount;
		static double interestRate;
		static double initRate();
		static constexpr int period = 30;
		double daily_tbl[period];
};

int main()
{
	
}
	
