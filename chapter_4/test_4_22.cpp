#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	int grade= 79;
	string finalgrade = (grade >90)?"high pass"
				:(grade>75)?"pass"
				:(grade>60)?"low pass"
				:"fail";
	if(grade>90)
		finalgrade = " high pass";
	else if(grade >75)
		finalgrade = "  pass";
	else if(grade >60)
		finalgrade = " low pass";
	else
		finalgrade = "fail";
}