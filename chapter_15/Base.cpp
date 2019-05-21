#include "Base.hpp"

int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public d4;
	Derived_from_Private d5;
	Derived_from_Protected d6;
	Base *p = &d1;
	///p = &d2;
	//p = &d3;
	//p = &d4;
	//p = &d5;
	//p = &d6;
}