#include <iostream>
#include <vector>

using namespace std;

struct X{
	X() {cout<<"X()"<<endl;}
	X(const X&){cout<< "X(const X&)"<<endl;}
	X& operator=(const &x){
		cout<<"operator=(const &x)"<<endl;
		return *this;
		}
	~X(){cout<<"~X()"<<endl;}
};

int main()
{
	vector<X> vX;
	cout<<"a"<<endl;
	X a;
	cout<<"b"<<endl;
	X b(a);
	cout<<"c"<<endl;
	X c = a;
	cout<<"d"<<endl;
	vX.push_back(a);
	cout<<"e"<<endl;
	X *e = new X;
	delete e;
	cout<<"f"<<endl;
	
}