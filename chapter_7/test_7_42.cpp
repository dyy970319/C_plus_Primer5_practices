#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

struct Date{
	public:
		Date(int d,int m,int y):day(d),month(m),year(y){}
		Date(int d):Date(d,12,2018){}
		Date(int d,int m):Date(d,m,2018){}		
	private:
		int year,month,day;
};



int main()
{
	
}
	
