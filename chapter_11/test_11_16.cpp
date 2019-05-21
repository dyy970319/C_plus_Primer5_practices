#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main()
{
	map<string,int> words;
	words["a"] =1;
	auto map_it = words.begin();
	map_it -> second = 3;
}