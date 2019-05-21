#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> dynamic_allocation(){
	//vector<int> *vi = new vector<int> ;
	//return vi;
	return make_shared<vector<int>>();
}

void print(shared_ptr<vector<int>> vi)
{
	for(auto beg = (*vi).begin(); beg != (*vi).end();++beg)
	{
		cout<<*beg<<endl;
	}
	//delete vi;
}

void read_save(istream &is,shared_ptr<vector<int>> vi){
	int temp;
	while(is>>temp){
		(*vi).push_back(temp);
	}
	print(vi);
	
}

int main()
{
	shared_ptr<vector<int>> vi = dynamic_allocation();
	read_save(cin,vi);
}