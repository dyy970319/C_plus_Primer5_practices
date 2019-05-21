#include <string>
#include <iostream>



class T{
	public:
		std::string mem1;
};


void swap(T v1,T v2)
{
	std::cout<<"mark"<<std::endl;
	using std::swap;
	std::swap(v1.mem1,v2.mem1);
}

class List{
};
class Db1List:public List,public List{
	
};


int main(){
	T t1,t2;
	swap(t1,t2);
	return 0;
}
