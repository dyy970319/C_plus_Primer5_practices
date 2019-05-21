#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	map<string,vector<string>> families = {
		{"tian",{"xia","kong"}}
		};
	families["feng"].push_back("yan");
	families["feng"].push_back("zi");
		cout<<families["tian"][0]<<endl;
}