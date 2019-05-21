#include <iostream>

using namespace std;

template <typename T,unsigned N>
void print(T (&p)[N])
{
	for(auto elem:p)
		cout<<elem<<endl;
}

template <typename T,typename U,typename V>void f1(T,U,V);

template<typename T> T f2(int &);

 template <typename T> inline T foo(T,unsigned int*);

template <typename T> void f4(T,T);

typedef char Ctype;
template<typename Ctype> Ctype f5(Ctype a);

/*template <typename U> void print(U &u)
{
	for(typename U::size_type i = 0;
		i != u.size();i++){
			print(u[i]);
		}
}*/

template <typename U> void print(U &u)
{
	for(auto beg = u.begin();beg != u.end();beg++){
			print(*beg);
		}
}