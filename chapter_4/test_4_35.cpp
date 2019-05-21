#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	/*char cval;
	cval = 'a' + 3;
	cout<<cval<<endl;
	
	unsigned int ui = 1;
	int ival = 1;
	float fval;
	fval = ui - ival*1.2;
	cout<<fval<<endl;*/
	
	/*char cval ;
	int ival = 50;
	float fval =1.5;
	double dval = 1.4;
	cval = ival +fval+dval;
	cout<<cval<<endl;*/
	void *pv;
	double d;
	pv = &d;
	pv = static_cast<void*>(&d);
}