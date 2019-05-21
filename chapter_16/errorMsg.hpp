#include <iostream>
#include "template_print.hpp"
#include "debug_rep.hpp"

using namespace std;

template<typename... Args>
ostream &errorMsg(ostream &os,const Args&... rest)
{
	return print(os,debug_rep(rest)...);
}

