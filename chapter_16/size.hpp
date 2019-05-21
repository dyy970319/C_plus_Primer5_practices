#include <iostream>

using namespace std;

template <typename T,unsigned N>
constexpr size_t size(T (&p)[N])
{
	return N;
}