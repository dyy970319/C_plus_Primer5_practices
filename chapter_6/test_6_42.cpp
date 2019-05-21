#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

inline string make_plural(size_t ctr,const string &word,
					const string &ending = "s")
{
	return (ctr > 1) ? word + ending :word;
}

constexpr bool isShorter(const string &s1,const string &s2)
{
	return  s1.size() < s2.size();
}

int main()
{
	string success = "success";
	string failure = "failure";
	string successes = make_plural(success.size(),success,"es");
	cout<<successes<<endl;
	string failures = make_plural(failure.size(),failure);
	cout<<failures<<endl;
}
	
