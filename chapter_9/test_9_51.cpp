#include <string>
#include <array>
#include <vector>
#include <iostream>

using namespace std;

class Date{
	vector<string> months = {"Jan","Feb","March","April","May","June",
		"July","August","September","October","November","December"};
	string numbers = "0123456789";
	public:
		Date(string s);
	private:
		unsigned y,m,d;
};

Date::Date(string s){
	bool hasFindMonth = false;
	int month_index = 0;
	for(auto beg = months.begin();beg != months.end();++beg)
	{
		string shorthand(*beg,0,3);
		if(s.find(shorthand) != string::npos){
			m = month_index + 1;
			hasFindMonth = true;
			break;
		}else{
			++month_index;
		}
	}
	int number_index = s.find_first_of(numbers); 
	int not_number_index = 0;
	if(hasFindMonth == false)
	{
		not_number_index = s.find_first_not_of(numbers);
		string month(s,number_index,not_number_index-number_index);
		m = stoi(month);
	}
	cout<<m<<endl;
	number_index = s.find_first_of(numbers,not_number_index);
	not_number_index = s.find_first_not_of(numbers,number_index);
	string day(s,number_index,not_number_index-number_index);
	d = stoi(day);
	cout<<d<<endl;
	
	number_index = s.find_first_of(numbers,not_number_index);
	string year(s,number_index);
	y = stoi(year);
	cout<<y<<endl;
}

int main()
{
	Date test = Date("Jan 1 1900");
	//cout<<test.y<<test.d<<test.m<<endl;
}