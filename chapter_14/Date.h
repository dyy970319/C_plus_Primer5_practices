#include <iostream>

using namespace std;

class Date{
	friend ostream &operator<<(ostream &,const Date &);
	friend istream &operator>>(istream &,Date &);
	friend Date operator - (const Date&,const Date&);
	friend bool operator == (const Date&,const Date&);
	friend bool operator != (const Date&,const Date&);
	friend bool operator < (const Date&,const Date&);
	friend bool operator > (const Date&,const Date&);
	public:
		Date() = default;
		Date(int y,int m,int d):
			year(y),month(m),day(d){}
		Date& operator -=(const Date&);
		explicit operator bool()const{
			return !(year == 0 && month == 0 && day == 0);
		}
	private:
		int year;
		int month;
		int day;
	
};