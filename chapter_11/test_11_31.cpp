#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	multimap<string,string> authors;
	auto cnt = authors.erase("Feng Yan");
	string search_item("handsome");
	for(auto pos = authors.equal_range(search_item);
		pos.first != pos.second; ++pos.first)
		cout<<pos.first -> second <<endl;
}