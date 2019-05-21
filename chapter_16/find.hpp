#include <iostream>

using namespace std;

template <typename T,typename U>
T find(const T &beg,const T&end,const U&value)
{
	T temp = beg;
	while(temp != end)
	{
		if(*temp == value)
			return temp;
		else
			++temp;
	}
	//cout<<"can't find"<<endl;
	return temp;
}