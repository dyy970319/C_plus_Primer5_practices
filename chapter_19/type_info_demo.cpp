#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

class Base{
	
};

class Derived : public Base{
	
};

class A{
	
};
class B : public A{
	
};
class C:public B{
	
};

class Sales_data{
	
};

string translate(string type_name){
	if(type_name == "i")
		type_name =  "Integer literal";
	else if(type_name == "A10_i")
		type_name = "An array of length 10";
	
	return type_name;
}



int main(){
	/*A *pa = new C;
	cout<<typeid(pa).name()<<endl;*/
	
	/*C cobj;
	A& ra =cobj;
	cout<<typeid(&ra).name()<<endl;*/
	
	B *px =new B;
	A &ra = *px;
	cout<<typeid(ra).name()<<endl;
	/*int arr[10];
	Derived d; 
	Base *p = &d;
	cout<<translate(typeid(42).name())<<", "
		<<typeid(arr).name()<<","
		<<typeid(Sales_data).name()<<","
		<<typeid(std::string).name()<<","
		<<typeid(p).name()<<","
		<<typeid(*p).name()<<endl;*/
	
}