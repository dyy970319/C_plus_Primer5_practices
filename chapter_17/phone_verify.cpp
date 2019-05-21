#include <regex>
#include <iostream>
#include <string>

using namespace std;

bool valid(const smatch& m)
{
	if(m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

int main()
{
	string phone = "(\\()?(\\d{3})([ ]*)(\\))?([-. ])?([ ]*)(\\d{3})([ ]*)([-. ]?)([ ]*)(\\d{4})";
	string postal_code = "(\\d{5})(([-])?(\\d{4}))?";
	string postal_code1 = "(\\d{5})(\\d{4})";
	regex r(postal_code1);
	smatch m;
	string s;
	string fmt = "$1-$2";
	while(getline(cin,s)){
		cout<<regex_replace(s,r,fmt);
	}
}