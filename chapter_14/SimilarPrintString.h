#include <iostream>
#include <vector>

using namespace std;

class SimilarPrintString{
	public:
		string operator()(istream &is){
			string s;
			if(getline(is,s)){
				v_str.push_back(s);
				return s;
			}
			else
				return "";
		}
	
	private:
		vector<string> v_str;
};