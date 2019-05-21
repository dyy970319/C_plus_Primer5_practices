#include <string>
#include <iostream>

using namespace std;

int main()
{
	string s1("ab2c3d7R4E6");
	string numbers("0123456789");
	char a = 'a';
	char A = 'A';
	string alphabets = "";
	for(int i = 0;i!=26;++i)
	{
		alphabets += (a+i);
		alphabets += (A+i);
	}
	
	string::size_type pos = 0;
	/*while((pos = s1.find_first_of(numbers,pos))
		!= string::npos){
		cout<< " found number at index: "<<pos
			<<" element is "<<s1[pos]<<endl;
		++pos;
	}
	pos = 0;
	while((pos = s1.find_first_of(alphabets,pos))
		!= string::npos){
		cout<< " found alphabet at index: "<<pos
			<<" element is "<<s1[pos]<<endl;
		++pos;
	}*/
	while((pos = s1.find_first_not_of(numbers,pos))
		!= string::npos){
		cout<< " found alphabet at index: "<<pos
			<<" element is "<<s1[pos]<<endl;
		++pos;
	}
	pos = 0;
	while((pos = s1.find_first_not_of(alphabets,pos))
		!= string::npos){
		cout<< " found number at index: "<<pos
			<<" element is "<<s1[pos]<<endl;
		++pos;
	}
}