#include <regex>
#include <iostream>

using namespace std;

int main(){
	string pattern("[^c]ei");
	pattern = "[[:alpha:]]*"+pattern+ "[[:alpha:]]*";
	regex r(pattern);
	smatch results;
	string file;
	while(cin >> file)
	{
		for(sregex_iterator it(file.begin(),file.end(),r),end_it;it != end_it; ++it)
		{
			if(it -> str() != "albeit" && it -> str() != "neighbor")
				cout<<it -> str() <<endl;
		}
		
	}
	
}