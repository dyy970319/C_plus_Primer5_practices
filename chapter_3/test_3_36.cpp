#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	constexpr size_t len = 2;
	int ia[len] = {0,0};
	int ib[len] = {0,0};
	/*if((end(ib)-begin(ib)) == (end(ia)-begin(ia))){
		int *pa = ia;
		int *pb = ib;
		for(;pa!=end(ia);pa++,pb++){
			if(*pa!=*pb){
				cout<<"don't equal"<<endl;
				break;
			}
		}
		if(pb==end(ib))
			cout<<"equal"<<endl;
	}
	else{
		cout<<"don't equal"<<endl;
	}*/
	vector<int> va(10,1);
	vector<int> vb(10,1);
	auto ita = va.begin();
	auto itb = vb.begin();
	for(;ita!=va.end();ita++,itb++){
		if(*ita != *itb){
			cout<<"don't equal"<<endl;
			break;
		}
	}
	if(itb == vb.end())
		cout<<"equal"<<endl;
	return 0;
	
	
}					