#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

int main()
{
	int grade = 60;
	const vector<string> scores = {"F","D","C","B","A","A++"};
	string lettergrade;
	/*if(grade<60)
		lettergrade = scores[0];
	else{
		lettergrade = scores[(grade - 50)/10];
		if(grade != 100)
			if (grade % 10 >7)
				lettergrade +='+';
			else if(grade%10<3)
				lettergrade +='-';
		}
	cout<<lettergrade<<endl;*/
	lettergrade = (grade < 60)?scores[0]
			:(scores[(grade - 50)/10]+((grade==100)?' ':
			(grade%10>7)?'+'
			:(grade%10<3)?'-'
			:' '));
	cout<<lettergrade<<endl;
			
	
}