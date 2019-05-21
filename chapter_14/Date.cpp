#include "Date.h"

ostream &operator<<(ostream &os,const Date &d)
{
	os<<d.year<<"/"<<d.month<<"/"<<d.day;
	return os;
}

istream &operator>>(istream &is,Date &d)
{
	is >> d.year >> d.month >>d.day;
	if(!is)
		d = Date();
	return is;
}

 Date operator - (const Date&d1,const Date&d2)
{
	Date d = d1;
	d -= d2;
	return d;
}

Date& Date::operator -=(const Date&d)
{
	if(this ->day < d.day)
		this -> month -= 1;
	this->day -= d.day;
	if(this ->month < d.month)
		this -> year -= 1;
	this->month -= d.month;
	this->year -= d.year;
	return *this;
}

bool operator == (const Date&d1,const Date&d2)
{
	return d1.year == d2.year &&
		d1.month == d2.month &&
		d1.day == d2.day;
}

bool operator != (const Date&d1,const Date&d2)
{
	return !(d1 == d2);
}

bool operator < (const Date&d1,const Date&d2)
{
	if(d1.year < d2.year)
		return true;
	else if(d1.year == d2.year){
		if(d1.month < d2.month)
			return true;
		else if(d1.month == d2.month){
			if(d1.day < d2.day)
				return true;
		}
	}
	return false;
}

bool operator > (const Date&d1,const Date&d2)
{
	return !(d1 == d2 || d1 < d2);
}


int main(){
	Date date1(1997,02,19);
	cout<<date1;
}