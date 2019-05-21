#include <iostream>
#include <cstring>
#include <vector>
#include <typeinfo>

using namespace std;
using std::vector;

class Y;
class X;

class X{
	Y *y;
};

class Y{
	X x;
};

