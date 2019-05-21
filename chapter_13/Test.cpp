#include "HasPtr.h"
#include "Foo.h"



int main()
{
	Foo f1,f2;
	f1.sorted().sorted();
	Foo retVal();
	//retVal().sorted();
	//retVal().sorted();
	//HasPtr h1;
	//HasPtr h2 = h1;
	//h1 = std::move(h2);
	//HasPtr *h3 = new HasPtr();
	/*vector<HasPtr> vh;
	HasPtr h1("a");
	HasPtr h2("b");
	HasPtr h3("c");
	HasPtr h4("d");
	HasPtr h5("f");
	HasPtr h6("a");
	
	vh.push_back(h1);
	vh.push_back(h2);
	vh.push_back(h3);
	vh.push_back(h4);
	vh.push_back(h5);
	vh.push_back(h6);
	sort(vh.begin(),vh.end());
	/*HasPtr h1("a");
	h1.test();*/
}