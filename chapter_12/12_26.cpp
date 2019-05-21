#include <string>
#include <memory>
#include <iostream>

using namespace std;

int main()
{
	/*string *const p = new string[n];
	string s;
	string *q = p;
	while(cin >> s && q != p + n)
		*q++ = s;
	const size_t size = q - p;
	delete[] p;*/
	int n = 3;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	auto q = p;
	string s;
	while(cin>>s && q != p + n){
		alloc.construct(q++,s);
	}
	cout<<*p<<endl;
	cout<<*(p+1)<<endl;
	cout<<*(p+2)<<endl;
	const size_t size = q - p ;
	/*while(q !=p)
		alloc.destroy(--q);	*/
	alloc.deallocate(p,n);
}