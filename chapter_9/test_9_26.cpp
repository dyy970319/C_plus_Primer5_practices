#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main()
{
	int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
	vector<int> vi;
	list<int> li;
	for(int i = 0 ; i != (sizeof(ia)/sizeof(ia[0])) ;++i){
		vi.push_back(ia[i]);
		li.push_back(ia[i]);
	}
	cout<<vi[3]<<endl;
	auto vi_beg = vi.begin();
	auto li_beg = li.begin();
	while(vi_beg != vi.end()){
		if(*vi_beg %2 == 0)
			vi_beg = vi.erase(vi_beg);
		else
			++vi_beg;
	}
	cout<<"dhfle"<<endl;
	while(li_beg != li.end()){
		if(*li_beg % 2 == 1)
			li_beg = li.erase(li_beg);
		else
			++li_beg;
	}
	cout<<"dlfhe"<<endl;
	cout<<vi[3]<<endl;
	cout<<*li.begin()<<endl;
	//vector<int> vi = ;
	//list<int> li = ia;
}