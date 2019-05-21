#include <regex>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(phone);
	smatch m;
	string s;
	string fmt = "$2.$5.$7";
	using namespace std::regex_constants;
	while(getline(cin,s)){
		if(regex_search(s,m,r)){
			//m.suffix().str()
			cout<<regex_replace(m.suffix().str(),r,fmt)<<endl;
		}
			//cout<<regex_replace(m.str(),r,fmt)<<endl;
		//cout<<regex_replace(s,r,fmt,format_no_copy).str(1)<<endl;
	}
		
	return 0;
	//morgan (201) 555-2368 862-555-0123
}