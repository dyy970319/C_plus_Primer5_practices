#include <iostream>

using namespace std;
class A{
};
class B:public A{
};
class C:public B{
};
class X{
};
class Y{
};
class Z:public X,public Y{
};
class MI:public C,public Z{
};
class D:public C,public X{
};

int main(){
	D *pd = new D;
	X *px = pd;
	A *pa =pd;
	B *pb = pd;
	C *pc = pd;
}