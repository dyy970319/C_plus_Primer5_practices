#include <list>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	list<int> li_test = {0,1,2};
	list<int>::iterator li_beg = li_test.begin(),li_end = li_test.end();
	vector<double> vd_test(li_beg,li_end);
	cout<<vd_test[0]<<endl;
	vector<int> vi_test(li_beg,li_end);
}