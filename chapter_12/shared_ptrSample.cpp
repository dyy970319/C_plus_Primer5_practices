#include <iostream>
#include <memory>

using namespace std;

struct destination{};
struct connection{};
connection connect(destination*d){
	
}
void disconnect(connection c){
}

void end_connection(connection *p){disconnect(*p);}

void fy_f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c,[](connection *p){
		disconnect(*p);
	});
}

int main()
{
	/*int p = 1;
	unique_ptr<int> ret(new int (p));
	unique_ptr<int> ret1(new int (p));
	
	*ret = 3;*/
	int ix = 1024,*pi = &ix,*pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	//IntP p0(ix);
	IntP p1(pi);
	IntP p2(pi2);
	IntP p3(&ix);
	IntP p4(new int(2048));
	IntP p5(p2.get());
	//p5 = nullptr;
	cout<<*p2<<endl;
	//unique_ptr<int> ret1 = ret;
}