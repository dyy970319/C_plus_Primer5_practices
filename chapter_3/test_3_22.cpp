#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	vector<string> text{"you're so"," handsome",""};
	for(auto it = text.begin();
		it != text.end() && !it->empty(); ++it){
		for(int i = 0 ; i <(*it).size(); i++)
			(*it)[i] = toupper((*it)[i]);
	}
	for(auto it = text.cbegin();
		it != text.cend() && !it->empty(); ++it){
		cout<<*it;
		}
}					