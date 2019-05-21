#include <iostream>

using namespace std;

template <typename T,unsigned N>
T* begin(T (&p)[N])
{
	return &p[0];
}

template <typename T,unsigned N>
T* end(T (&p)[N])
{
	return &p[N];
}